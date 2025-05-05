// Program to implement stack ADT using singly linked list

#include <cstdio>
#include <cstdlib>

class Stack
{
    struct node
    {
        char data;
        struct node *next;
    };
    struct node *head;
public:
    Stack()
    {
        head = NULL;
    }
    void Push(char val);
    void Pop();
    void Peek();
};

int main()
{
    Stack obj;
    int chc;
    char val;
    while(1)
    {
        printf("\nMENU:\n");
        printf(" 1. Push \n 2. Pop \n 3. Peek \n 4. Exit \n");
        printf("Enter you chc: ");
        scanf("%d", &chc);

        switch(chc)
        {
            case 1:
                printf("Enter the character to be pushed into the stack: ");
                scanf(" %c", &val);
                obj.Push(val);
                break;
            case 2:
                obj.Pop();
                break;
            case 3:
                obj.Peek();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input\n");
                break;
        }
    }
}

//Function to Push (To insert a element to the top of the stack)
void Stack::Push(char val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

//Function to Pop (To remove the top element in the stack)
void Stack::Pop()
{
    if(head == NULL)
    {
        printf("The stack is empty.");
    }
    else
    {
        head = head->next;
    }
}

//Function to Peek (To see the top element in the stack)
void Stack::Peek()
{
    if(head == NULL)
    {
        printf("The stack is empty.");
    }
    printf("The top element is: %c", head->data);
}

