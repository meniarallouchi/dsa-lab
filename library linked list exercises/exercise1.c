#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
    char title[100];
    char author[50];
    int year;
    float price;
    struct Book* next;
};
typedef struct Book Book;

Book* createBook(char* title,char* author, int year,float price){
    Book* newBook=(Book*)malloc(sizeof(Book));
    if (newBook==NULL){ printf("allocation failed\n"); return NULL; }
    strcpy(newBook->title,title);
    strcpy(newBook->author,author);
    newBook->year=year;
    newBook->price=price;
    newBook->next =NULL;
    return newBook;
}

Book* insertBookAtBeginning(Book* head, char* title, char* author, int year, float price){
    Book* newBook=createBook(title,author, year, price);
    if (newBook==NULL) return head;

    newBook->next=head;
    return newBook;
}

Book* insertBookAtEnd(Book* head, char* title, char* author, int year, float price){
    Book* newBook=createBook(title,author, year, price);
    if (newBook==NULL) return head;

    if (head==NULL) return newBook;

    Book* current=head;
    while (current->next!=NULL){
        current=current->next;
    }
    current->next=newBook;
    return head;
}