#include <stdio.h>

int main()
{
    char grade;
    printf("enter a grade (A-F): ");
    scanf(" %c",&grade);
    
    switch(grade){
        case 'A':
            printf("excellent\n");
            break;
            
        case 'B':
            printf("good job\n");
            break;
            
        case 'C':
            printf("average\n");
            break;
            
        case 'D':
            printf("below average\n");
            break;
            
        case 'F':
            printf("failed\n");
            break;
            
        default: //handles invalid input
            printf("invalid grade\n");
            break;
    }
    return 0;
}