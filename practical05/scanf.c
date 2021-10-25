#include <stdio.h>

int main(void)
{
    int i;
    double a;
    
    printf("Enter an int and a double, seperately by (,)\n");
    //get 2 inputs int and float
    scanf("%d, %lf", &i, &a);
    //display inputs that just got above
    printf("You have entered %d, and %lf\n", i, a);
    
    //assign i's address to pointer_to_i
    int *pointer_to_i = &i;
    //display value from i directly
    printf("The value i is %d\n",i);
    //display value in the address of pointer
    printf("The value i is also %d\n", *pointer_to_i);
    //display address of i
    printf("The address of i is %d\n", &i);

    return 0;

}
