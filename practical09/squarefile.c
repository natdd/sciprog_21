#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 100
#include"magic_square.h"

// function to get number of lines in file
int getlines(char filename[MAX_FILE_NAME]);

int main()
{
  //define file and get file name and open file 
  FILE *f;
  char filename[MAX_FILE_NAME];
  printf("Enter file name: ");
  scanf("%s",filename);
  f = fopen(filename,"r"); 
  
  //get number of line for n dimension of matrix
  int n = getlines(filename);
   
  //allocate matrix
  int i;
  int ** magicSquare = malloc(n*sizeof(int));
  
  for(i=0;i<n;i++) {
    magicSquare[i] = malloc(n*sizeof(int));
  }

  //loop to get matrix elements from file
  int j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++) 
      fscanf(f,"%d",&magicSquare[i][j]);
  }

  printf("The square %s magic.\n",isMagicSquare(magicSquare,n) ? "is" : "is NOT");

  //free array
  for(i=0;i<n;i++)
     free(magicSquare[i]);

  free(magicSquare);

  //close file
  fclose(f);
  return 0;
}

int getlines(char filename[MAX_FILE_NAME])
{
  FILE *fp;
  fp = fopen(filename, "r");
  
  int ch_read;
  int count = 0;

  //read file and count no of lines until end of file
  while((ch_read = fgetc(fp)) != EOF)
  {
    if(ch_read == '\n') {
      count++;     
    }
  }

  printf("No of lines: %d\n",count);
  fclose(fp);
  return count;
}
