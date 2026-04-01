#include <stdio.h>

int main()
{
    //vars
    float num1,num2,result;
    char operation; // + - * /
    
    //welcome message
    printf("=== simple calculator ===\n");
    
    //input from user
    printf("enter first number: ");
    scanf("%f",&num1);
    
    printf("enter second number: ");
    scanf("%f",&num2);
    
    printf("enter operation (+, -, *, /): ");
    scanf(" %c",&operation);
    
    //switch statement
    switch(operation)
    {
        case '+':
            result=num1+num2;
            printf("\n%.2f+%.2f=%.2f\n",num1,num2,result);
            break;
            
        case '-':
            result=num1-num2;
            printf("\n%.2f-%.2f=%.2f\n",num1,num2,result);
            break;
            
        case '*':
            result=num1*num2;
            printf("\n%.2f*%.2f=%.2f\n",num1,num2,result);
            break;
            
        case '/':
            //div by zero
            if (num2==0) {
                printf("error: division by zero is not allowed!\n");
            } else {
                result=num1/num2;
                printf("\n%.2f/%.2f=%.2f\n",num1,num2,result);
            }
            break;
            
        default:
            printf("error: invalid operation, please use +, -, *, /\n");
            break;
    }
    return 0;
}