#include <stdio.h>

int main()
{
    int n,sum=0;
    printf("enter n:"); //input
    scanf("%d",&n);
    
    //loop from 1 to n
    for (int i=1;i<=n;i++){ //in python (for i in range(1,n+1):)
        printf("%d\n",i);
        sum+=i;  //add current number to sum, same as sum=sum+i
    }
    
    printf("sum: %d\n",sum); //output
    return 0;
}