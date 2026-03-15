#include <stdio.h>

int main()
{
    int rows;
    printf("enter num of rows: ");
    scanf("%d",&rows);
    
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=i;j++){  //inner loop prints i stars in row i, in python (for j in range(i):)
            printf("*");
        }
        printf("\n"); //new line after each row
    }
    return 0;
}

//nested for loops
//outer loop controls the rows
//inner loop controls how many stars to print in each row