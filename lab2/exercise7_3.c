#include <stdio.h>

int main()
{
    int arr[12];
    printf("enter 12 integers: ");
    for (int i=0;i<12;i++)
    {
        scanf("%d",&arr[i]);
    }

    int earr[12]; //creating a new array
    int j=0; //index for the new array
    for (int i=0;i<12;i++)
    {
        if (arr[i]%2==0) //check if the number is even
        {
            earr[j]=arr[i]; //add the even number to the new array
            j++; //increment the index for the new array
        }
    }

    printf("even numbers: ");
    for (int i=0;i<j;i++)
    {
        printf("%d ",earr[i]);
    }
    return 0;
}