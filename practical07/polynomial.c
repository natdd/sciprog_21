#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//calculate factorial used in polynomial function
int factorial(int n) {
  if(n==0) return 1;
  else return n*factorial(n-1);
}

double compute_polynomial(int n, int x)
{
  double sum = 0.0;
  int i;

  //loop to accumulate each term
  for(i=0;i<=n;i++)
     sum = sum + (double)pow(x,i)/factorial(i);

  return sum;
}

int main()
{
  int order_of_polynomial;
  int size_of_array;
  double* array_of_terms;
  int i, x=1;

  //get number of polynomial order
  printf("Enter the order of polynomial: ");
  scanf("%d",&order_of_polynomial);

  //define size and allocate memomry for array to keep each accumulated term
  size_of_array = order_of_polynomial + 1;
  array_of_terms = (double *)malloc(size_of_array * sizeof(double));
  
  //compute and print calculated polynomial
  for(i=0; i<size_of_array; i++)
  {
    array_of_terms[i] = compute_polynomial(i,x);
    printf("f[%d] = %0.20f\n",i,array_of_terms[i]);
  }

  //actual value
  printf("e1 = %0.20f\n",exp(1));

  //compare with actual value
  for(i=0; i < size_of_array; i++)
    printf("Estimate difference for term %d is %0.20f\n",i,exp(1) - array_of_terms[i]);

  //free memory and set pointer to null safely 
  free(array_of_terms);
  array_of_terms = NULL;


  return 0;
}
