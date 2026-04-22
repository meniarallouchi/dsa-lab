#include <stdio.h>

int main()
{
    int arr[7];
    int *p;

    printf("enter 7 numbers: ");
    for (p=arr;p<arr+7;p++)
    {
        scanf("%d",p);
    }

    printf("reverse: ");
    for (p=arr+6;p>=arr;p--)
    {
        printf("%d ",*p);
    }
    printf("\n");
    return 0;
}