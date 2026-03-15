#include <stdio.h>

int main()
{
    int nStudents;
    printf("enter number of students (max 50): ");
    scanf("%d",&nStudents);

    while (nStudents<1 || nStudents>50) //validate input
    {
        printf("invalid number of students. Please enter a number between 1 and 50: ");
        scanf("%d",&nStudents);
    }

    char names[nStudents][100]; //max 50 students, each name can be up to 99 characters + null terminator (\0)
    int scores[nStudents][3]; //max 50 students, each with 3 scores

    printf("enter names of students and their scores: \n");
    for (int i=0;i<nStudents;i++)
    {
        printf("student %d:\n",i+1);
        printf("name: ");
        scanf(" %s",names[i]); //read name (no spaces)
        printf(names[i]);
    }
    return 0;
}