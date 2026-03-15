#include <stdio.h>

int main()
{
    int choice;
    float num1,num2,result;
    printf("menu:\n");
    printf("1.addition\n");
    printf("2.subtraction\n");
    printf("3.multiplication\n");
    printf("4.division\n");

    printf("enter your choice: ");
    scanf("%d",&choice);

    printf("enter first number: ");
    scanf("%f",&num1);
    
    printf("enter second number: ");
    scanf("%f",&num2);
    
    switch(choice){
        case 1:
            result=num1+num2;
            printf("result: %.0f\n",result);  //%.0f displays float with 0 decimal places
            break;
            
        case 2:
            result=num1-num2;
            printf("result: %.0f\n",result);
            break;
            
        case 3:
            result=num1*num2;
            printf("result: %.0f\n",result);
            break;
            
        case 4:
            if (num2==0){ //division by zero
                printf("error division by zero\n");
            }else{
                result=num1/num2;
                printf("result: %.2f\n",result);  //show 2 decimal places
            }
            break;
            
        default:
            printf("invalid choice please select from 1 to 4.\n");
            break;
    }
    return 0;
}