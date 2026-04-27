#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void print_list(struct Node *head){
    struct Node* current=head;
    printf("list: ");
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

struct Node* find(struct Node* head,int value){
    struct Node* current=head;
    while (current!=NULL){
        if (current->data==value)
            return current;     //found i, return the node
        current=current->next;
    }
    return NULL;   //reached end without finding it
}

int main()
{
    struct Node* head=NULL;

    head=insert_beginning(head,10);
    head=insert_beginning(head,20);
    head=insert_beginning(head,30);

    print_list(head);

    if (find(head,20)!=NULL){
        printf("found 20\n");
    }else{
        printf("did not find 20\n");
    }
    
    if (find(head,99)!=NULL){
        printf("found 99\n");
    }else{
        printf("did not find 99\n");
    }
    return 0;
}