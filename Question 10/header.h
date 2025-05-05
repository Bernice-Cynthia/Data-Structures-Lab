#ifndef HEADER_H
#define HEADER_H
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
        List();
        int gethead();
        void insbeg(int);
        void insend(int);
        void inspos(int, int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
};

int List::gethead()
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

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

#endif
