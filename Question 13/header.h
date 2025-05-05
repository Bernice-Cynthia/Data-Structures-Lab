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
    int isValid(string s);
};

void Stack::Push(char val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

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

void Stack::Peek()
{
    if(head == NULL)
    {
        printf("The stack is empty.");
    }
    printf("The top element is: %c", head->data);
}
