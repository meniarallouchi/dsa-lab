#include <stdio.h>

int main()
{
    int age; //declare a var to store age
    printf("enter your age: "); //display to the user
    scanf("%d",&age); //integer input from user
    
    //check if age is 18 or older
    if (age>=18){
        printf("you are eligible to vote\n");
    }
    return 0;
}