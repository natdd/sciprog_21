#include <stdio.h>
#include <math.h>

double arctanh1(const double x, const double delta);
double arctanh2(const double x);

int main()
{
  //get input for precision
  double prec;
  printf("Enter precision for the Macluarin series:\n");
  scanf("%lf",&prec);
  //get input for start and end point for calculation
  double begin,end;
  printf("Enter the start and end points for x:\n");
  scanf("%lf, %lf", &begin, &end);
  
  //calculate size of array
  double a = ((fabs(begin)+fabs(end))/prec) + 1;
  int asize = a;

  //define array to keep result each point from arctanh functions
  double tan1[asize];
  double tan2[asize];

  double i;
  //index in array
  int j=0;

  //loop to calculate using both functions
  for(i=begin; i <= end; i+=prec)
  {
      tan1[j] = arctanh1(i,prec);
      tan2[j] = arctanh2(i);
      //display difference of results from different functions
      printf("The difference between tan1[%.3lf] and tan2[%.3lf] is %.10lf\n",i,i,fabs(tan1[j] - tan2[j]));
      j++;
  } 

  return 0;
}

//calculate the inverse hyperbolic tangent of x
//with a precision error of less than 'delta'
//assume -1 < x < 1 and delta > 0
double arctanh1(const double x, const double delta)
{
  double arcTan = 0;
  double elem;
  int n = 0;

  do {
    
	double val = 2*n+1;
	elem = pow(x, val)/val;
        arcTan += elem;
	n++;

  } while(fabs(elem) >= delta);
  
  return arcTan;
}

//calculate the inverse hyperbolic tangent of x
double arctanh2(const double x) 
{
  return (log(1+x)-log(1-x))/2;
}
