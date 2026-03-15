#include <stdio.h>

int main()
{
    int num;
    int *p=&num;
    printf("enter an integer: ");
    scanf("%d",&num);

    printf("you entered: %d\n",num);

    *p=100; //dereferencing the pointer p to assign a new value to num
    
    printf("after changing the value through pointer, num is: %d\n",num);
    return 0;
}