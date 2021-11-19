#include<stdio.h>
#include<stdlib.h>
#include"magic_square.h"

int main()
{
  //get size of matrix to allocate matrix and  retrieve elements
  int n;
  printf("Enter the square size:\n");
  scanf("%d", &n);
  
  //allocate matrix
  int i;
  int ** magicSquare = malloc(n*sizeof(int));
  
  for(i=0;i<n;i++) {
    magicSquare[i] = malloc(n*sizeof(int));
  }

  //get elements from user
  int j;
  for(i=0;i<n;i++)
  {
    printf("Enter the elements in row #%d, separated by blank and/or linebreak:\n",i+1);
    for(j=0;j<n;j++) scanf("%d",&magicSquare[i][j]);
  }

  //return result by calling function from header file
  printf("The square %s magic.\n",isMagicSquare(magicSquare,n) ? "is" : "is NOT");

  //free array
  for(i=0;i<n;i++)
     free(magicSquare[i]);

  free(magicSquare);

  return 0;
}
