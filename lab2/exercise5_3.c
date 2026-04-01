#include <stdio.h>

int main()
{
    int num;
    printf("enter numbers: ");

    while (1){  // 1=true in C
        scanf("%d",&num);
        if (num==0){
            break;
        }

        if (num<0){
            continue;
        }
        printf("%d squared= %d\n",num,num*num);
    }
    return 0;
}