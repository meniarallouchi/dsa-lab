#include <stdio.h>

int main()
{
    int num1,num2; //declare var to store usee input
    //declare var to store result
    int addition,subtraction,multiplication,modulus;
    float division; //2 decimal resut
    
    //input from user
    printf("enter first number: ");
    scanf("%d",&num1);
    
    printf("enter second number: ");
    scanf("%d",&num2);
    
    //arithmetic operations
    addition=num1+num2;
    subtraction=num1-num2;
    multiplication=num1*num2;
    division=(float)num1/num2; //float for decimal result
    modulus=num1%num2;
    
    //output
    printf("\n%d+%d=%d\n",num1,num2,addition);
    printf("%d-%d=%d\n",num1,num2,subtraction);
    printf("%d*%d=%d\n",num1,num2,multiplication);
    printf("%d/%d=%.2f\n",num1,num2,division);
    printf("%d %% %d=%d\n",num1,num2,modulus);
    return 0;
}