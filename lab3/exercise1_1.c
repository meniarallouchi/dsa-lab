#include <stdio.h>

int main()
{
    int x=42;
    int *ptr=&x; //ptr is a pointer to an integer and it holds the address of x

    printf("value of x: %d\n",x);
    printf("address of x: %p\n",&x); //%p is used to print the address in hexadecimal format
    printf("value of ptr: %p\n",ptr); //ptr holds the address of x, so it should print the same address as &x
    printf("value pointed to by ptr: %d\n",*ptr); //(*ptr) dereferences the pointer to get the value it points to

    return 0;
}