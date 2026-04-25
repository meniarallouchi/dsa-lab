#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[50];
    float gpa;
    int age;
    struct Student* next;
};
typedef struct Student Student;

Student* createStudent(char* name, float gpa, int age){
    Student* newStudent=(Student*)malloc(sizeof(Student));
    if (newStudent==NULL){
        printf("memory allocation failed\n");
        return NULL;
    }
    strcpy(newStudent->name,name);
    newStudent->gpa=gpa;
    newStudent->age=age;
    newStudent->next=NULL;
    return newStudent;
}

void printStudentList(Student* head){
    Student* current=head;
    while (current!=NULL){
        printf("%s (gpa: %.1f, age: %d)", current->name, current->gpa, current->age);
        if (current->next!=NULL)
            printf(" -> ");
        current=current->next;
    }
    printf(" -> NULL\n");
}

Student* insertStudentAtEnd(Student* head, char* name, float gpa, int age){
    Student* newStudent=createStudent(name,gpa, age);
    if (newStudent==NULL) return head;

    if (head==NULL) return newStudent;

    Student* current=head;
    while (current->next!=NULL){
        current=current->next;
    }
    current->next=newStudent;
    return head;
}

Student* deleteStudentByName(Student* head, char* targetName){
    if (head==NULL){
        printf("list is empty\n");
        return NULL;
    }

    if (strcmp(head->name,targetName)==0){
        Student* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    Student* prev=head;
    Student* current=head->next;

    while (current!=NULL){
        if (strcmp(current->name,targetName)==0){
            prev->next=current->next;
            free(current);
            return head;
        }
        prev=current;
        current=current->next;
    }

    printf("student %s not found\n",targetName);
    return head;
}

Student* deleteStudentsBelowGPA(Student* head, float threshold){
    while (head!=NULL && head->gpa<threshold){
        Student* temp=head;
        head=head->next;
        free(temp);
    }

    if (head==NULL) return NULL;

    Student* prev=head;
    Student* current=head->next;

    while (current!=NULL){
        if (current->gpa<threshold){
            prev->next=current->next;
            free(current);
            current=prev->next;
        }else{
            prev=current;
            current=current->next;
        }
    }
    return head;
}

Student* deleteOldestStudent(Student* head){
    if (head==NULL){
        printf("list is empty\n");
        return NULL;
    }

    int maxAge=head->age;
    Student* current=head->next;
    while (current!=NULL){
        if (current->age>maxAge) maxAge=current->age;
        current=current->next;
    }

    if (head->age==maxAge){
        Student* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    Student* prev=head;
    current=head->next;
    while (current!=NULL){
        if (current->age==maxAge){
            prev->next=current->next;
            free(current);
            return head;
        }
        prev=current;
        current=current->next;
    }
    return head;
}

int main()
{
    Student* head=NULL;

    head=insertStudentAtEnd(head,"Alice",3.8,20);
    head=insertStudentAtEnd(head,"Bob",3.5,21);
    head=insertStudentAtEnd(head,"Carol",3.9,19);
    head=insertStudentAtEnd(head,"David",2.7,22);
    head=insertStudentAtEnd(head,"Eva",3.2,20);

    printf("initial list:\n");
    printStudentList(head);

    head=deleteStudentByName(head,"Carol");
    printf("\nafter deleteStudentByName(Carol):\n");
    printStudentList(head);

    head=deleteStudentsBelowGPA(head,3.5);
    printf("\nater deleteStudentsBelowGPA(3.5):\n");
    printStudentList(head);

    head=deleteOldestStudent(head);
    printf("\nafter deleteOldestStudent:\n");
    printStudentList(head);

    Student* current=head;
    while (current!=NULL){
        Student* temp=current;
        current=current->next;
        free(temp);
    }
    return 0;
}