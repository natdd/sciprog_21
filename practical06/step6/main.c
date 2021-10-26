#include<stdio.h>

int main()
{
  //array size
  int n=5, p=3, q=4;
  //array for matrix
  double A[n][p], B[p][q], C[n][q];
  
  //for matrix calculation loop
  int i, j, k;
   
  //initial A,B and C matrices
  for(i=0; i<n; i++)
  {
    for(j=0; j<p; j++)
    {
	A[i][j] = i+j;
    }
  }

  for(i=0; i<p; i++)
  {
    for(j=0; j<q; j++)
    {
	B[i][j] = i-j;
    }
  }

  for(i=0; i<n; i++)
  {
    for(j=0; j<q; j++)
    {
	C[i][j] = 0.0;
    }
  }
 
  //perform matrix multiplication
  matmul(n,p,q,A,B,C);
  //for(i=0; i<n; i++)
  // for(j=0; j<q; j++)
  //  for(k=0; k<p; k++)
  //    C[i][j] = C[i][j]+A[i][k]*B[k][j]; 
 
  //print matrix A
  printf("\nThe matrix A is:\n");
  for(i=0; i<n; i++)
  {
    for(j=0; j<p; j++)
    {
	printf("%3.0f",A[i][j]);
    }
    printf("\n");
  }

  //print matrix B
  printf("\nThe matrix B is:\n");
  for(i=0; i<p; i++)
  {
    for(j=0; j<q; j++)
    {
	printf("%3.0f",B[i][j]);
    }
    printf("\n");
  }

  //print matrix C
  printf("\nThe matrix C is:\n");
  for(i=0; i<n; i++)
  {
    for(j=0; j<q; j++)
    {
	printf("%3.0f",C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
