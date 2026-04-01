#include <stdio.h>

int main()
{
    int arr[10]; //array declaration, it reserves space for 10 integers but does not initialize them
    int num, found=0; //flag to indicate if the number is found or not

    printf("enter 10 integers: ");
    for (int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]); //array initialization, it assigns the value entered by the user
    }

    printf("enter a number to search in the array: ");
    scanf("%d",&num);

    //searching for the number in the array
    for (int i=0;i<10;i++)
    {
        if (arr[i]==num)
        {
            found=1;
            printf("number found at index %d\n",i);
            break; //exit the loop
        }else{
            continue; //continue to the next iteration of the loop
        }
    }
    if (found==0) printf("number not found in the array\n");
    return 0;
}