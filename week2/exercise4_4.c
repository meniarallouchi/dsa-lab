#include <stdio.h>

int main()
{   
    for (int i=2;i<51;i+=2){  //loop through even numbers
        printf("%d ",i);  //with a space
        if (i%10==0){
            printf("\n");
        }
    }
    return 0;
}