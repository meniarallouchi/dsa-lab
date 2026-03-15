#include <stdio.h>

int main()
{
    int num1,num2; //declare vars
    
    //input
    printf("enter first number: ");
    scanf("%d",&num1);
    printf("enter second number: ");
    scanf("%d",&num2);
    
    //nested if statements to compare the numbers
    //outer if checks if num1 is greater
    if (num1>num2){
        printf("%d is larger than %d\n",num1,num2);
    }else{
        //inner if checks if they are equal or num2 is greater
        if (num1==num2){
            printf("%d is equal to %d\n",num1,num2);
        }else{
            printf("%d is larger than %d\n",num2,num1);
        }
    }
    return 0;
}