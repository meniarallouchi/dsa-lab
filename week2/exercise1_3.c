#include <stdio.h>

int main()
{
    int score; //declare a var
    printf("enter your score: "); //display
    scanf("%d",&score); //input
    
    //assign grades
    if (score>=90 && score<=100){
        printf("grade:A\n");
    }else if(score>=80 && score<=89){
        printf("grade:B\n");
    }else if(score>=70 && score<=79){
        printf("grade:C\n");
    }else if(score>=60 && score<=69){
        printf("grade:D\n");
    }else if(score>=0 && score<60){
        printf("grade:F\n");
    }else{
        //invalid scores
        printf("invalid score enter a score between 0 and 100.\n");
    }
    return 0;
}