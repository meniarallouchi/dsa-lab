#include <stdio.h>

int main()
{
    //var of different types
    int myInt= 42;
    float myFloat=3.14;
    double myDouble=2.71828;
    char myChar='A';
    
    //displaying each var
    printf("integer: %d\n",myInt);
    printf("float: %f\n",myFloat);
    printf("double: %lf\n",myDouble);
    printf("character: %c\n",myChar);
    printf("character as integer (ASCII): %d\n",myChar);
    return 0;
}