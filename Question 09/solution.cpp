//Menu driven program to implement List ADT using circular linked list

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
};

int main()
{
    List cll;
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
                cll.insbeg(num);
                break;
            case 2:
                printf("Enter number to be Inserted at End: ");
                scanf("%d", &num);
                cll.insend(num);
                break;
            case 3:
                printf("Enter the Position: ");
                scanf("%d", &out);
                printf("Enter number to be Inserted at Position: ");
                scanf("%d", &num);
                cll.inspos(num, out);
                break;
            case 4:
                out = cll.delbeg();
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
                out = cll.delend();
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
                out = cll.delpos(num);
                if (out < 0)
                {
                    printf("The List is Empty \n");
                }
                else if (out == 0)
                {
                    printf("Invalid Position \n");
                }
                else
                {
                    printf("The element Deleted at Position %d is %d", num, out);
                }
                break;
            case 7:
                printf("Enter the number you want to Search:");
                scanf("%d", &num);
                out = cll.search(num);
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
                cll.display();
                break;
            case 9:
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
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        struct node* temp=head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next=newnode;
        head = newnode;
    }
}

//Function to Insert at the End
void List::insend(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

//Function to Insert at Position
void List::inspos(int num, int out)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (out < 0)
    {
        printf("Invalid Position");
    }
    if (out == 1 || head == NULL)
    {
        insbeg(num);
    }
    else
    {
        struct node *temp = head;
        for (int i = 1; temp->next != NULL && i < out-1; i++)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            printf("Invalid Position");
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
    int dat = head->data;
    if (head->next == NULL)
    {
        head = NULL;
        return dat;
    }
    struct node* temp=head->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next=head;
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
    if (temp->next == head)
    {
        int dat = temp->data;
        head = NULL;
        return dat;
    }
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    int dat = temp->next->data;
    temp->next = head;
    return dat;
}

//Function to Delete at Position
int List::delpos(int num)
{
    if (head == NULL)
    {
        return -1;
    }
    if (num == 1)
    {
        return delbeg();
    }
    struct node *temp = head;
    for (int i = 1; temp != NULL && i < num-1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        return 0;
    }
    struct node *tofree = temp->next;
    int dat = tofree->data;
    temp->next = tofree->next;
    free(tofree);
    return dat;
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
    while (temp->next != head)
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
        while (temp->next != head)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> HEAD \n", temp->data);
    }
}

