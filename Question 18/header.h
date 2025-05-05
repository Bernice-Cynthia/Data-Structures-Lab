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
    bool empty();
    void push(char val);
    void pop();
    char peek();
};

void Stack::push(char val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void Stack::pop()
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

char Stack::peek()
{
    if(head == NULL)
    {
        printf("The stack is empty.");
    }
    return head->data;
}

bool Stack::empty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
