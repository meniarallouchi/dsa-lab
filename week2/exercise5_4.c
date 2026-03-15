#include <stdio.h>

int main()
{
    int num, max, count=0, first=0; //if i initialize max without giving it a value it will store a random number not 0 or anything

    printf("enter numbers: ");
    scanf("%d",&num);
    max=num; //initialize max to the first number

    while (num!=-1){
        if (first){
            max=num;
            first=0;  //noo longer the first number
        }else{
            if (num>max){ //update max if current number is larger
                max=num;
            }
        }
        count++;  //count this number
        scanf("%d",&num);  //read next number
    }
    
    if (count>0){
        printf("maximum: %d \nnumbers entered: %d",max,count);
    }else{
        printf("no numbers were entered.\n");
    }
    return 0;
}