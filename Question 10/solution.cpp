//Menu driven program to implement ROUND-ROBIN SCHEDULING using circular linked list(queue)

#include "circular.h"

void insert(int, List&);
void execute(int, List&);

List::List()
{
    head=NULL;
}

int main()
{
    int chc, slot;
    List obj;
    printf("Enter the time slot: ");
    scanf("%d", &slot);
    while (1) 
    {
        printf("\nMENU\n ");
        printf("1. Insertion \n 2. Execution \n 3. Exit \n ");
        printf("Enter your choice: ");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
                int num;
                printf("Enter the number to be Inserted: ");
                scanf("%d", &num);
                insert(num, obj);
                break;
            case 2: 
                execute(slot, obj);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    } 
}

//Function to Insert (get in Queue)
void insert(int num, List& obj)
{
    obj.List::insend(num);
    obj.List::display();
}

//Function to Execute (Queue moves forward)
void execute(int slt, List& obj)
{
    int x = obj.List::gethead();
    if (x!=0)
    {
        int ret = obj.List::delbeg();
        ret = ret - slt;
        if (ret <= 0)
        {
            printf("Operation was successful \n");
        }
        else
        {
            obj.List::insend(ret);
            printf("Operation was successful \n");
        }
    }
    else
    {
        printf("The Queue is empty\n");
    } 
    obj.List::display();   
}
