#include <stdio.h>

int main()
{
    //vars
    char ch,nextChar,prevChar,oppositeCase;
    
    //input from the user
    printf("enter a character: ");
    scanf(" %c",&ch);
    
    //calculate next and previous chars
    nextChar=ch+1;
    prevChar=ch-1;
    
    //opposite case
    if (ch>='A' && ch<='Z') {
        //char is uppercase => convert to lowercase
        oppositeCase=ch+32;
    } else if (ch>='a' && ch<='z') {
        //char is lowercase => convert to uppercase
        oppositeCase=ch-32;
    } else {
        //not an alphabetic char
        oppositeCase=ch;
    }
    
    //display results
    printf("character: %c\n",ch);
    printf("ASCII value: %d\n",ch);
    printf("nxt character: %c\n",nextChar);
    printf("previous character: %c\n",prevChar);
    printf("opposite case: %c\n",oppositeCase);
    return 0;
}