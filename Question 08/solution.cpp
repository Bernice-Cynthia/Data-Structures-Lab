//Menu driven Program for Doubly Linked List
#include <cstdio>
#include <cstdlib>

class List 
{
    struct node 
    {
        int data;
        struct node *next;
        struct node *prev;
    };
    struct node *head;
    struct node *tail;
    public: 
        List()
        {
            head = NULL;
            tail = NULL;
        }
        void insbeg(int);
        void insend(int);
        void inspos(int, int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
};

int main()
{
    List dll;
    int chc, num, out;
    while (1)
    {
        printf("\nMENU\n ");
        printf("1. Insertion at Beginning  \n 2. Insertion at End \n 3. Insertion at Position \n ");
        printf("4. Deletion at Beginning  \n 5. Deletion at End \n 6. Deletion at Position \n ");
        printf("7. Search \n 8. Display \n 9. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &chc);

        switch (chc)
        {
            case 1:
                printf("Enter number to be Inserted at Beginning: ");
                scanf("%d", &num);
                dll.insbeg(num);
                break;
            case 2:
                printf("Enter number to be Inserted at End: ");
                scanf("%d", &num);
                dll.insend(num);
                break;
            case 3:
                printf("Enter the Position: ");
                scanf("%d", &out);
                printf("Enter number to be Inserted at Position: ");
                scanf("%d", &num);
                dll.inspos(num, out);
                break;
            case 4:
                out = dll.delbeg();
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
                out = dll.delend();
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
                out = dll.delpos(num);
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
                out = dll.search(num);
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
                dll.display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}

//Function to Insert at Beginning
void List::insbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->next = NULL;
    }
    else 
    {
        struct node *temp = head;
        head = newnode;
        temp->prev = newnode;
        newnode->next = temp;
    }
}

//Function to Insert at End
void List::insend(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;

    if (head == NULL)
    {
        insbeg(num);
    }
    else 
    {
        struct node *temp = tail;
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
    }
}

//Function to Insert at Position
void List::inspos(int num, int pos)
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
        for (int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Invalid position. \n");
        }
        if (temp->next == NULL)
        {
            newnode->next = NULL;
            tail = newnode;
        }
        else
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

//Function to Delete at the Beginning
int List::delbeg()
{
    if (head == NULL)
    {
        return -1;
    }
    int temp = head->data;
    if (head->next == NULL)
    {
        head = NULL;
        return temp;
    }
    head = head->next;
    head->prev = NULL;
    return temp;
}

//Function to Delete at the End
int List::delend()
{
    if (head == NULL)
    {
        return -1;
    }
    int temp = tail->data;
    if (tail->prev == NULL)
    {
        tail = NULL;
        head = NULL;
        return temp;
    }
    tail = tail->prev;
    tail->next = NULL;
    return temp;
}

//Function to Delete at Position
int List::delpos(int pos)
{
    if (head == NULL)
    {
        return -1;
    }
    if (pos == 1)
    {
        return delbeg();
    }
    struct node *temp = head;
    for (int i = 1;temp != NULL && i < pos-1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return 0;
    }
    if (temp->next == tail)
    {
        return delend();
    }
    int data = temp->next->data;
    temp->next = temp->next->next;
    temp->next->prev = temp;

    return data;
}

//Function to Search an element in the List
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

//Function to Display the elements of the List
void List::display()
{
    if(head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp=head;
    struct node *emp = tail;

    printf("Forward :  ");
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

    printf("Backward:  ");
    while(emp != NULL)
    {
        printf("%d -> ",emp->data);
        emp=emp->prev;
    }
    printf("NULL\n");
}

