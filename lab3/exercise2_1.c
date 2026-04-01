#include <stdio.h>

int main()
{
    int arr[5]={10,20,30,40,50};
    int *p=arr;
    /*ptr points to the first element of the array (arr is equivalent to &arr[0]):
    int *ptr=&arr[0];
    */

    printf("using array subscript: arr[i]: ");
    for (int i=0;i<5;i++){
        printf(" %d",arr[i]);
    }

    printf("\nusing pointer and subscript: p[i]: ");
    for (int i=0;i<5;i++){
        printf(" %d",p[i]);
    }

    printf("\nusing pointer arithmetic: *(p+i): ");
    for (int i=0;i<5;i++){
        printf(" %d",*(p+i));
    }
    return 0;
}