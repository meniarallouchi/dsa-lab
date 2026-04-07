#include <stdio.h>

struct Student{
    char name[50];
    int age;
    float grade;
};

void printStudent(struct Student students){
    printf("student: %s, age %d, grade %.2f\n",students.name,students.age,students.grade);
}

void showAll(struct Student students[]){
    for (int i=0;i<6;i++){
        printStudent(students[i]);
    }
}

void showHighest(struct Student students[]){
    int highest=0;
    for (int i=1;i<6;i++){
        if (students[i].grade>students[highest].grade){
            highest=i;
        }
    }
    printf("highest grade:\n");
    printStudent(students[highest]);
}

void showLowest(struct Student students[]){
    int lowest=0;
    for (int i=1;i<6;i++){
        if (students[i].grade<students[lowest].grade){
            lowest=i;
        }
    }
    printf("lowest grade:\n");
    printStudent(students[lowest]);
}

void searchByName(struct Student students[]){
    char input[50];
    printf("enter name to search: ");
    scanf("%49s",input);

    int found=0;
    for (int i=0;i<6;i++) {
        int match=1;
        for (int j=0;students[i].name[j]!='\0' || input[j]!='\0';j++){  //walk through both strings char by char until both hit '\0'
            if (students[i].name[j]!=input[j]){
                match=0;
                break;
            }
        }
        if (match==1){
            printStudent(students[i]);
            found=1;
        }
    }
    if (found==0){
        printf("no student found with the name %s.\n",input);
    }
}

int main()
{
    int choice;
    struct Student students[6]={
        {"mia",19,19.5},
        {"lynx",21,17.0},
        {"bob",20,13.0},
        {"sara",22,9.5},
        {"amir",18,11.0},
        {"nadia",20,14.75}
    };

    do{
        printf("menu:\n");
        printf("1. show all students\n");
        printf("2. show highest grade\n");
        printf("3. show lowest grade\n");
        printf("4. search by name\n");
        printf("5. exit\n");
        printf("your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                showAll(students);
                break;
            case 2:
                showHighest(students);
                break;
            case 3:
                showLowest(students);
                break;
            case 4:
                searchByName(students);
                break;
            case 5:
                printf("bye\n");
                break;
            default:
                printf("invalid option\n");
                break;
        }
    }while (choice!=5);
    return 0;
}