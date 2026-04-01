#include <stdio.h>

int main()
{
    int arr[8], sum=0, max, min;
    float avg;

    printf("enter 8 integers: ");
    for (int i=0;i<8;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }

    avg=sum/8.0;
    
    max=arr[0];
    min=arr[0];
    for (int i=1;i<8;i++){
        if (arr[i]>max) max=arr[i];
        if (arr[i]<min) min=arr[i];
    }

    printf("sum: %d\n",sum);
    printf("average: %.2f\n",avg);
    printf("max: %d\n",max);
    printf("min: %d\n",min);

    return 0;
}