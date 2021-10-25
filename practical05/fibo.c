#include <stdio.h>
#include <stdlib.h>

void fibo(int *a, int *b);

int main()
{
   int n;
   
   //get input of number of fibonacci sequence
   printf("Enter a positive integer for n: \n");
   scanf("%d", &n);  

   //check if number is negative and terminate program
   if (n < 1) {
      printf("Numner less than 1\n");
      exit(1);

   }

   //initial first 2 fibonocci numbers
   int n1 = 0;
   int n2 = 1;

   printf("The Fibonacci sequence is: \n");
   printf("%d, ",n1);

   int i;
   for(i=1;i < n-1;i++)
   {
      fibo(&n1,&n2);
      printf("%d, ", n1);
   }

   printf("%d\n",n2);

   return 0;
} 

//fibo function to sum previous 2 values (inputs)
//using pointer to get address (update value in the address directly without return)
void fibo(int *a, int *b)
{
   int next;
   next = *a + *b;
   //update 2 previous values
   *a = *b;
   *b = next;
}
