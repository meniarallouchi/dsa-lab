#include <stdio.h>

int main()
{
    int arr[]= {10,20,30,40,50};
    int *start= &arr[0];
    int *end= &arr[4];
    int count= end-start+1;

    printf("first: %d, last: %d\n",*start,*end);
    printf("num of elements: %d\n",count);
    return 0;
}