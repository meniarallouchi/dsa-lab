#include <stdio.h>

struct student{
    char name[50];
    int age;
    float grade;
};

int main()
{
    struct student s;

    printf("enter name: ");
    scanf("%49s", s.name);   //read at most 49 characters (last slot is reserved for the \0)
    
    printf("enter age: ");
    scanf("%d", &s.age);

    printf("enter grade: ");
    scanf("%f", &s.grade);

    printf("student %s (age %d) has grade %0.2f",s.name,s.age,s.grade);
    return 0;
}