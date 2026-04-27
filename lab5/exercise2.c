#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void print_list(struct Node *head){
    struct Node* current=head;
    while (current!=NULL){
        printf("%d ",current->data);
        current= current->next;
    }
    printf("\n");
}

struct Node* insert_beginning(struct Node *head,int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) return head;

    newNode->data= value;
    newNode->next= head;
    return newNode;
}

int main()
{
    struct Node* head=NULL;

    head=insert_beginning(head,3);
    head=insert_beginning(head,2);
    head=insert_beginning(head,1);

    print_list(head);
    return 0;
}