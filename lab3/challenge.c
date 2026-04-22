#include <stdio.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int arraySum(int *arr, int size)
{
    int sum=0;
    int *p;
    for (p=arr;p<arr+size;p++){
        sum+=*p;
    }
    return sum;
}

int main()
{
    int x,y;
    printf("enter two numbers: ");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("before swap: %d %d\n",x,y);
    swap(&x, &y);
    printf("ater swap:  %d %d\n",x,y);

    int size;
    printf("enter array size: ");
    scanf("%d",&size);

    int arr[size];
    printf("enter %d numbers: ",size);
    int *p;
    for (p=arr;p<arr+size;p++){
        scanf("%d",p);
    }

    printf("sum: %d\n",arraySum(arr,size));
    return 0;
}