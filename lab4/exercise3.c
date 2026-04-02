#include <stdio.h>

struct Student{
    char name[50];
    int age;
    float grade;
};


int main()
{
    float sum=0;
    struct Student s[5];

    printf("enter name, age and grade for each student:\n" );
    for (int i=0;i<5;i++){
        printf("student %d:\n",i+1);
        printf("name: ");
        scanf("%49s",s[i].name);
        printf("age: ");
        scanf("%d",&s[i].age);
        printf("grade: ");
        scanf("%f",&s[i].grade);
        sum+=s[i].grade;
    }

    for(int i=0;i<5;i++){
        printf("student %d: %s, age %d, grade %0.2f\n",i+1,s[i].name,s[i].age,s[i].grade);
    }
    printf("class average: %0.2f",sum/5);
    return 0;
}