#include <stdio.h>

int main()
{
    int arr[6];
    printf("enter 6 integers: ");
    for (int i=0;i<6;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int *ptr=arr, sum=0, max=*ptr;
    for (int i=0;i<6;i++)
    {
        sum+=*(ptr+i);
        if (max<*(ptr+i)) max=*(ptr+i);
    }
    printf("sum: %d\nmax: %d",sum,max);
    return 0;
}