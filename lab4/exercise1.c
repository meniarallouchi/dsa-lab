#include <stdio.h>

struct student{
    char name[50];
    int age;
    float grade;
};

int main()
{
    struct student s={"alice",20,16.50};
    printf("name: %s\nage: %d\ngrade: %.2f",s.name,s.age,s.grade);
    return 0;
}