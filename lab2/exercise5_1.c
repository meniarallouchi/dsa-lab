#include <stdio.h>

int main()
{
    int num, count=0, sum=0;
    printf("enter positive nums\n");
    scanf("%d",&num); //first num

    while (num!=0){
        count++; //increment count
        sum+=num; //add to sum
        scanf("%d",&num); //next number
    }

    printf("count: %d \nsum %d",count,sum);
    return 0;
}