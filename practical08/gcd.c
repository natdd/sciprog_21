#include<stdio.h>

//Declare function to get GCD
int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);

int main(void)
{
  int a,b,error;

  //get 2 numbers as inputs
  printf("Please input two positive integers\n");
  error = scanf("%d %d",&a,&b);
  
  //check if input recieved successfully
  if(error != 2)
  {
    printf("Please try again\n");
    return 1;
  }
  
  //inputs must be greater than 0 
  if(a<=0 || b<=0)
  {
    printf("These numbers are not positive!\n");
    return 1;
  }
  
  //call functions
  printf("Iterative gcd(%d, %d)=%d\n", a, b,iterativeGCD(a,b));
  printf("Recursive gcd(%d, %d)=%d\n", a, b,recursiveGCD(a,b));
  return 0;
}

//Calculate GCD using loop
int iterativeGCD(int a, int b)
{
  int temp;
  while(b!=0)
  {
    temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}

//Calculate GCD using recursive
int recursiveGCD(int a, int b)
{
  if(b==0)
     return a;    
  else 
     return(recursiveGCD(b, a%b));
}
