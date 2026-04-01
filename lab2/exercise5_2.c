#include <stdio.h>

int main()
{
    int choice;
    do {
        printf("menu:\n");
        printf("1.display hello\n");
        printf("2.display world\n");
        printf("3.exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("hello\n");
                break;
                
            case 2:
                printf("world\n");
                break;
                
            case 3:
                printf("goodbye\n");
                break;
                
            default:
                printf("invalid choice!\n");
                break;
        }
        
    }while (choice!=3);  //continue until user enters 3
    return 0;
}

//do while loop executes at least once then checks condition
//while loop which checks condition first