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

Student* insertStudentAtBeginning(Student* head, char* name, float gpa, int age){
    Student* newStudent=createStudent(name,gpa, age);
    if (newStudent==NULL) return head;

    newStudent->next=head;
    return newStudent;
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

Student* insertStudentAtPosition(Student* head, char* name, float gpa, int age, int pos){
    if (pos<=1) return insertStudentAtBeginning(head,name,gpa,age);

    Student* newStudent=createStudent(name,gpa,age);
    if (newStudent==NULL) return head;

    Student* current=head;
    int i=1;
    while (current!=NULL && i<pos-1){
        current=current->next;
        i++;
    }

    if (current==NULL){
        printf("position out of range\n");
        free(newStudent);
        return head;
    }

    newStudent->next=current->next;
    current->next=newStudent;
    return head;
}

int main()
{
    Student* head=NULL;

    head=insertStudentAtEnd(head,"Carol",3.9,19);
    printf("after insertAtEnd (Carol): ");
    printStudentList(head);

    head=insertStudentAtEnd(head,"David",2.7,22);
    printf("after insertAtEnd (David): ");
    printStudentList(head);

    head=insertStudentAtEnd(head,"Eva",3.2,20);
    printf("after insertAtEnd (Eva): ");
    printStudentList(head);

    head=insertStudentAtBeginning(head,"Alice",3.8,20);
    printf("\nafter insertAtBeginning (Alice): ");
    printStudentList(head);

    head=insertStudentAtPosition(head,"Bob",3.5,21,2);
    printf("\nafter insertAtPosition 2 (Bob): ");
    printStudentList(head);

    Student* current=head;
    while (current!=NULL){
        Student* temp=current;
        current=current->next;
        free(temp);
    }
    return 0;
}