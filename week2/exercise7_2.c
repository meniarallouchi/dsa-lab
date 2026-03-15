#include <stdio.h>

int main()
{
    int arr[15], pSum=0, nSum=0, zSum=0;
    printf("enter 15 integers: ");
    for (int i=0;i<15;i++)
    {
        scanf("%d",&arr[i]);
        if (arr[i]>0) pSum++;
        else if (arr[i]<0) nSum++;
        else zSum++;
    }
    printf("positive: %d\nnegative: %d\nzeros: %d\n", pSum, nSum, zSum);
    return 0;
}