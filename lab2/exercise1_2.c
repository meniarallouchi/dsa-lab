#include <stdio.h>

int main()
{
    int number; //declare a var
    printf("enter a number: ");  //display
    scanf("%d",&number);  //input

    //check if the number is +
    if (number>=0){
        printf("the number is positive\n");
    }else{
        printf("the number is not positive\n");
    }
    return 0;
}