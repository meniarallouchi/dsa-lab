#include <stdio.h>

int main()
{
    //declare var to store user input
    int age;
    float height;
    char initial;
    
    //enter var
    printf("enter your age: ");
    scanf("%d",&age);
    
    printf("enter your height (in meters): ");
    scanf("%f",&height);

    printf("enter your first initial: ");
    scanf(" %c",&initial);
    
    //output
    printf("you entered:\n");
    printf("age: %d years old\n",age);
    printf("height: %.2f meters\n",height);
    printf("initial: %c\n",initial);
    return 0;
}