/* sourced from:
    https://www.geeksforgeeks.org/c/linked-list-in-c/
    https://www.geeksforgeeks.org/c/c-program-to-implement-singly-linked-list/
    https://www.w3schools.com/dsa/dsa_theory_linkedlists.php

A linked list is a linear data structure used to store elements of the same data type but not in contiguous memory locations.
It is a collection of nodes where each node contains a data field and a next pointer indicating the address of the next node.
So only the current node in the list knows where the next element of the list is stored.

Each node has:
    Data: The value stored in the node.
    Pointer: A reference to the next node.

Nodes are not stored in contiguous memory like arrays; they can be anywhere in memory.
To access a node, we start from the head and traverse sequentially through the list. */

#include <stdio.h>
#include <stdlib.h> //this library is used for dynamic memory allocation (malloc, free)

// Define the node structure
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    // Create nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Check allocation
    if (!head || !second || !third) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign data and link nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Print linked list
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free allocated memory
    temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}

/* Output
    10 -> 20 -> 30 -> NULL

Types of Linked List in C
    Linked list can be classified on the basis of the type of structure they form as a whole and the direction of access.
    Based on this classification, there are three basic types of linked lists:
    1. Singly Linked List: Each node has a pointer to the next node. Traversal is one-way.
    2. Doubly Linked List: Each node has pointers to both the next and previous nodes.
    3. Circular Linked List: The last node points back to the head, forming a circle.

Singly Linked List in C
    A singly linked list is a type of linked list where only the address of the next node is stored in the current node along with the data field and the last node in the list contains NULL pointer.
    This makes it impossible to find the address of the particular node in the list without accessing the node previous to it.
    So we can only access the data sequentially in the node.
    Each node has two parts:
        the data, and the pointer to the next node.
    The last node's (also known as tail) pointers point to NULL to indicate the end of the linked list.

Representation of Singly Linked List in C
    To represent a node of a singly linked list in C,
    we will use a structure that will have two data members data and next where:
*/
struct Node {    
        int data;  //data: indicates the value stored in the node.
        struct Node *next;  //next: is a pointer that will store the address of the next node in the sequence.
};

/*
The following diagram represents the structure of a singly linked list:
    head -> [data | next] -> [data | next] -> [data | NULL]
In this diagram:
    head: is a pointer that points to the first node of the linked list.
    [data | next]: represents a node in the linked list where data is the value stored in the node and next is a pointer to the next node in the list.
    The last node's next pointer is NULL, indicating the end of the list.

Singly Linked List Basic Operations in C

Operation        | Type                | Description                                                 | Time Complexity | Space Complexity
------------------------------------------------------------------------------------------------------------------------------------------
INSERT           | At Head            | Appends a new node at the start of the singly linked list    | O(1)            | O(1)
INSERT           | At Given Position  | Adds a new node at a specific position in the linked list    | O(N)            | O(1)
INSERT           | At End             | Adds a new node to the end of the singly linked list         | O(N)            | O(1)

DELETE           | From Head          | Removes the first node from the singly linked list           | O(1)            | O(1)
DELETE           | From Given Position| Deletes a node at a specific position in the linked list     | O(N)            | O(1)
DELETE           | From End           | Eliminates the last node of the singly linked list           | O(N)            | O(1)

PRINT            |         -          | Iterates through the list and prints each node’s data        | O(N)            | O(1)
    Note: Here N represents the number of nodes in the linked list.

Insertion Operation Implementation

    1. Algorithm for insertAtFirst Function
        Create a new node.
        If the linked list is empty set the new node as the Head and return.
        Connect the next pointer of this new node to the Head of the linked list.
        Update the Head pointer and make it points to the new node.
    
    2. Algorithm for insertAtPosition Function
        If it is 0, call the insertAtFirst function to insert the node at the first position of the list.
        Check if the position is 0.
        Initialize a counter variable and a temporary pointer to traverse the linked list.
        Iterate over the linked list to find the node before the insertion point (position - 1).
            If the temporary pointer becomes NULL before reaching the desired position, the position is out of range.
            Return.
        Create a new node.
        Point the next pointer of the new node to the node present just after the temporary pointer.
        Point the next pointer of the temporary node to the new node and return.

    3. Algorithm for insertAtEnd Function
        Create a new Node.
        If the list is empty, update the Head pointer to be this new node and then return.
        Otherwise traverse till the last node of the singly linked list.
        Connect next pointer of the last node to the new node.

Deletion Operations in a Singly Liked List in C

    1. Algorithm for deleteFromFirst Function
        Ensure that the Head of the linked list is not NULL; if it is, the list is empty, so return.
        Create a temporary pointer and point it to the current Head of the list.
        Update the current head of the singly linked list to the next node.
        Point the next pointer of the temporary node to NULL to detach it from the singly linked list.
        Delete the temporary node.

    2. Algorithm for deleteFromPosition Function
        If it is NULL, the linked list is empty, so return.
        Check if the head pointer of the linked list is NULL.
        Check if the position is 0.
            If it is 0, call the deleteFromFirst function to delete the first node.
        Initialize a counter variable and a temporary pointer to traverse the linked list.
        Iterate the linked list to find the node before the deletion point (position - 1).
        If the temporary pointer becomes NULL before reaching the desired position the position is out of range. Return
        Store the next node of the temporary pointer in a temporary pointer.
        Update the next pointer of the temporary pointer to the next pointer of the node to be deleted.
        Delete the node represented by the temporary pointer.

    3. Algorithm for deleteFromEnd Function
        Ensure that the Head of the linked list is not NULL; if it is, the list is empty, so return.
        If the singly linked list has only one node, delete the head node and point the head pointer to NULL.
        Traverse till the second last node of the singly linked list.
        Store the next node of the second last node in a temporary pointer.
        Connect the next pointer of the second last node to NULL.
        Delete the last node represented by the temporary pointer.

Algorithm for Print Function

    Check if the HEAD of the singly linked is is NULL or not. If NULL return back.
    Set a temp pointer to the head of the singly linked list.
    While temp pointer != NULL:
        Print temp->data.
        Move temp to temp->next

Program for Implementation of Singly Linked List   */

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new element at the end of the singly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a new element at a specific position in the singly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        insertAtFirst(head,data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node of the singly linked list
void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node of the singly linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position in the singly linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        deleteFromFirst(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to print the LinkedList
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver Code
int main() {
    struct Node* head = NULL;
    
    insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head); 
    
    printf("Linked list after inserting the node:20 at the end \n");
    insertAtEnd(&head, 20);
    print(head); 
    
    printf("Linked list after inserting the node:5 at the end \n");
    insertAtEnd(&head, 5);
    print(head); 
    
    printf("Linked list after inserting the node:30 at the end \n");
    insertAtEnd(&head, 30);
    print(head); 
    
    printf("Linked list after inserting the node:15 at position 2 \n");
    insertAtPosition(&head, 15, 2);
    print(head);
    
    printf("Linked list after deleting the first node: \n");
    deleteFromFirst(&head);
    print(head); 
    
    printf("Linked list after deleting the last node: \n");
    deleteFromEnd(&head);
    print(head); 
    
    printf("Linked list after deleting the node at position 1: \n");
    deleteAtPosition(&head, 1);
    print(head); 

    return 0;
}

/* Output

Linked list after inserting the node:10 at the beginning 
    10 -> NULL
Linked list after inserting the node:20 at the end 
    10 -> 20 -> NULL
Linked list after inserting the node:5 at the end 
    10 -> 20 -> 5 -> NULL
Linked list after inserting the node:30 at the end 
    10 -> 20 -> 5 -> 30 -> NULL
Linked list after inserting the node:15 at position 2 
    10 -> 20 -> 15 -> 5 -> 30 -> NULL
Linked list after deleting the first node: 
    20 -> 15 -> 5 -> 30 -> NULL
Linked list after deleting the last node: 
    20 -> 15 -> 5 -> NULL
Linked list after deleting the node at position 1: 
    20 -> 5 -> NULL
*/