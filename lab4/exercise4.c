#include <stdio.h>
#include <string.h>

struct Student{
    char name[50];
    int age;
    float grade;
};

void printStudent(struct Student s){
    printf("student: %s, age %d, grade %.2f\n", s.name, s.age, s.grade);
}

int isPassed(struct Student s){
    if (s.grade>=10){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    struct Student s={"sara", 18, 15.00};
    printStudent(s);

    if (isPassed(s)==1){
        printf("%s passed\n", s.name);
    }else{
        printf("%s failed\n", s.name);
    }
    return 0;
}