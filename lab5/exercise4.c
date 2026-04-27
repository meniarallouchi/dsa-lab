#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void print_list(struct Node *head){
    if (head==NULL){
        printf("(empty)\n");
        return;
    }
    struct Node* current=head;
    while (current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}

struct Node* insert_beginning(struct Node *head,int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) return head;
    newNode->data=value;
    newNode->next=head;
    return newNode;
}

struct Node* delete_beginning(struct Node *head){
    if (head==NULL) return NULL;

    struct Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

int main()
{
    struct Node* head=NULL;

    head=insert_beginning(head,3);
    head=insert_beginning(head,4);
    head=insert_beginning(head,5);

    printf("before: ");
    print_list(head);

    head=delete_beginning(head);
    printf("after one delete: ");
    print_list(head);

    head=delete_beginning(head);
    head=delete_beginning(head);
    printf("after deletes: ");
    print_list(head);
    return 0;
}