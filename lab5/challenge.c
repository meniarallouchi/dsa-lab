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

struct Node* find(struct Node *head,int value){
    struct Node* current=head;
    while (current!=NULL){
        if (current->data==value)
            return current;
        current=current->next;
    }
    return NULL;
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
    int choice,value;

    do{
        printf("=== linked list menu ===\n");
        printf("1. insert at beginning\n");
        printf("2. print list\n");
        printf("3. search for a value\n");
        printf("4. delete at beginning\n");
        printf("5. exit\n");
        printf("choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("enter value: ");
                scanf("%d",&value);
                head=insert_beginning(head,value);
                printf("%d inserted\n",value);
                break;

            case 2:
                printf("list: ");
                print_list(head);
                break;

            case 3:
                printf("enter value to search: ");
                scanf("%d",&value);
                if (find(head,value)!=NULL)
                    printf("found %d\n",value);
                else
                    printf("did not find %d\n",value);
                break;

            case 4:
                if (head==NULL)
                    printf("list is already empty\n");
                else{
                    printf("deleted %d\n",head->data);
                    head=delete_beginning(head);
                }
                break;

            case 5:
                printf("bye\n");
                break;

            default:
                printf("invalid choice try again\n");
                break;
        }

    }while (choice!=5);

    while (head!=NULL){
        struct Node* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}