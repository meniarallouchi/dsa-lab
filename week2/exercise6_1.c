#include <stdio.h>

int main()
{
    int arr[5]={10,20,30,40,50};
    
    printf("the elements of the array are:\n");
    for (int i=0;i<5;i++){
        printf("index %d: %d\n",i,arr[i]);
    }
    return 0;
}