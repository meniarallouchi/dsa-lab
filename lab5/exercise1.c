#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void print_list(struct Node *head){
    if (head== NULL){
        printf("(empty)\n");
        return;
    }

    for (struct Node *current= head; current!= NULL; current= current->next){
        printf("%d ",current->data);
    }
    printf("\n");
}

int main()
{
    struct Node *head= NULL;
    print_list(head);
    return 0;
}