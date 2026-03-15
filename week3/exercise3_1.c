#include <stdio.h>

void doubleValue (int *ptr)
{
    *ptr = *ptr*2;
}

int main()
{
    int var=5;
    printf("before: var= %d\n",var);
    doubleValue(&var);
    printf("after: var= %d",var);
    return 0;
}