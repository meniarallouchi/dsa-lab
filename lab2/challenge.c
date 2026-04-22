#include <stdio.h>

char getGrade(float avg)
{
    if (avg>=90) return 'A';
    else if (avg>=80) return 'B';
    else if (avg>=70) return 'C';
    else if (avg>=60) return 'D';
    else return 'F';
}

int main()
{
    int nStudents;
    printf("enter number of students (max 50): ");
    scanf("%d",&nStudents);

    while (nStudents<1 || nStudents>50)
    {
        printf("invalid number enter a number between 1 and 50: ");
        scanf("%d",&nStudents);
    }

    char names[nStudents][100];
    int scores[nStudents][3];
    float averages[nStudents];

    for (int i=0;i<nStudents;i++)
    {
        printf("enter student %d name: ",i+1);
        scanf(" %s",names[i]);

        printf("enter 3 test scores: ");
        int sum=0;
        for (int j=0;j<3;j++)
        {
            scanf("%d",&scores[i][j]);
            sum+=scores[i][j];
        }
        averages[i]=sum/3.0;
    }

    int choice;
    do
    {
        printf("\nmenu:\n");
        printf("1. display all students and grades\n");
        printf("2. find student with highest average\n");
        printf("3. find student with lowest average\n");
        printf("4. display class average\n");
        printf("5. exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("\n");
                for (int i=0;i<nStudents;i++)
                {
                    printf("student: %s, average: %.2f, grade: %c\n",names[i],averages[i],getGrade(averages[i]));
                }
                break;

            case 2:
            {
                int maxIndex=0;
                for (int i=1;i<nStudents;i++)
                {
                    if (averages[i]>averages[maxIndex])
                        maxIndex=i;
                }
                printf("\nhighest: %s, average: %.2f, grade: %c\n",names[maxIndex],averages[maxIndex],getGrade(averages[maxIndex]));
                break;
            }

            case 3:
            {
                int minIndex=0;
                for (int i=1;i<nStudents;i++)
                {
                    if (averages[i]<averages[minIndex])
                        minIndex=i;
                }
                printf("\nlowest: %s, average: %.2f, grade: %c\n",names[minIndex],averages[minIndex],getGrade(averages[minIndex]));
                break;
            }

            case 4:
            {
                float total=0;
                for (int i=0;i<nStudents;i++)
                    total+=averages[i];
                printf("\nclass Average: %.2f\n", total/nStudents);
                break;
            }

            case 5:
                printf("exit\n");
                break;

            default:
                printf("invalid choice enter a number between 1 and 5.\n");
        }
    } while (choice!=5);
    return 0;
}