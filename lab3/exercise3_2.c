#include <stdio.h>

void readArray(int *arr, int size)
{
    printf("enter %d ints: ",size);
    for (int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

int main()
{
    int arr[5];
    readArray(arr,5);
    printf("\narray: ");
    for (int i=0;i<5;i++)
    {
        printf(" %d",arr[i]);
    }
    return 0;
}