//Menu driven program to implement List ADT using singly linked list

#include <cstdio>
#include <cstdlib>

class List 
{
    struct node 
    {
        int data;
        struct node *next;
    };
    struct node *head;
    public:
        List()
        {
            head = NULL;
        }
        void insbeg(int);
        void insend(int);
        void inspos(int, int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
        void disrev();
        void reverse();
};

int main()
{
    List sll;
    int chc, num, out;
    while (1)
    {
        printf("\nMENU\n ");
        printf("1. Insertion at Beginning  \n 2. Insertion at End \n 3. Insertion at Position \n ");
        printf("4. Deletion at Beginning  \n 5. Deletion at End \n 6. Deletion at Position \n ");
        printf("7. Search \n 8. Display \n 9. Display in Reverse \n10. Reverse Link \n11. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &chc);

        switch (chc)
        {
            case 1:
                printf("Enter number to be Inserted at Beginning: ");
                scanf("%d", &num);
                sll.insbeg(num);
                break;
            case 2:
                printf("Enter number to be Inserted at End: ");
                scanf("%d", &num);
                sll.insend(num);
                break;
            case 3:
                printf("Enter the Position: ");
                scanf("%d", &out);
                printf("Enter number to be Inserted at Position: ");
                scanf("%d", &num);
                sll.inspos(num, out);
                break;
            case 4:
                out = sll.delbeg();
                if (out < 0)
                {
                    printf("The List is Empty \n");
                }
                else
                {
                    printf("The element Deleted at Beginning is %d", out);
                }
                break;
            case 5:
                out = sll.delend();
                if (out < 0)
                {
                    printf("The List is Empty \n");
                }
                else
                {
                    printf("The element Deleted at the End is %d", out);
                }
                break;
            case 6:
                printf("Enter the Position: ");
                scanf("%d", &num);
                out = sll.delpos(num);
                if (out < 0)
                {
                    printf("The List is Empty \n");
                }
                else
                {
                    printf("The element Deleted at Position %d is %d", num, out);
                }
                break;
            case 7:
                printf("Enter the number you want to Search:");
                scanf("%d", &num);
                out = sll.search(num);
                if (out < 0)
                {
                    printf("The given number does not exist in the list. \n");
                }
                else if (out == 0)
                {
                    printf("The List is Empty \n");
                }
                else
                {
                    printf("The given number is found at Index %d. \n", out);
                }
                break;
            case 8:
                sll.display();
                break;
            case 9:
                sll.disrev();
                break;
            case 10:
                sll.reverse();
                printf("The List has been Reversed \n");
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}

//Function to Insert at the Beginning
void List::insbeg(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

//Function to Insert at the End
void List::insend(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

//Function to Insert at Position
void List::inspos(int num, int out)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        struct node *temp = head;
        for (int i = 1; i < out-1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

//Function to Delete at the Beginning
int List::delbeg()
{
    if (head == NULL)
    {
        return -1;
    }
    struct node *temp = head;
    int dat = temp->data;
    head = temp->next;
    return dat;
}

//Function to Delete at the End
int List::delend()
{
    if (head == NULL)
    {
        return -1;
    }
    struct node *temp = head;
    if (temp->next == NULL)
    {
        int dat = temp->data;
        head = NULL;
        return dat;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int dat = temp->next->data;
    temp->next = NULL;
    return dat;
}

//Function to Delete at Position
int List::delpos(int num)
{
    if (head == NULL)
    {
        return -1;
    }
    struct node *temp = head;
    for (int i = 0; i+1 < num; i++)
    {
        temp = temp->next;
    }
    /*temp = temp->next;
    int dat = temp->data;
    temp= temp->next; 
    return dat;
    TO BE CORRECTED*/
    
}

//Function to search an element in the List
int List::search(int num)
{
    if (head == NULL)
    {
        return 0;
    }
    struct node *temp = head;
    int i = 0;
    while (temp->next != NULL)
    {
        i++;
        if (temp->data == num)
        {
            return i;
        }
        temp = temp->next;
    }
    i++;
    if (temp->data == num)
    {
        return i;
    }
    return -1;
}

//Function to Display the List
void List::display()
{
    if (head == NULL)
    {
        printf("The List is Empty. \n");
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> NULL \n", temp->data);
    }
}

//Function to Display in Reverse
void List::disrev()
{
    reverse();
    display();
    reverse();
}

//Function to Reverse the List
void List::reverse()
{
    if (head == NULL)
    {
        printf("The List is Empty. \n");
    }
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *temp = NULL;
    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
}
