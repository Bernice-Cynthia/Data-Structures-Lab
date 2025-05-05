#ifndef MERGE_H
#define MERGE_H

class List 
{
    struct node 
    {
        int data;
        struct node* next;
    } *head;

    struct node* gethead();

    public:
        List();

        struct node* callgethead() 
        {
            return gethead();
        }

        int insert(int);
        void merge(List&, List&);
        void display();
        int insert_list1(int);
        int insert_list2(int);
        void merge_2(List& obj1, List& obj2);
};


//Function to Insert data
int List::insert(int num) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
        printf("Memory Allocation failed\n");
        return 0;
    }
    newnode->data = num;
    newnode->next = NULL;

    if ((head == NULL) || (head->data >= num)) 
    {
        newnode->next = head;
        head = newnode;
        return 1;
    }

    struct node* temp = head;
    while ((temp->next != NULL) && (temp->next->data < num)) 
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}

//Function to Merge 2 Lists
void List::merge(List& obj1, List& obj2) 
{
    struct node* head1 = obj1.callgethead();
    struct node* head2 = obj2.callgethead();

    head = NULL;
    struct node** tail = &head;

    while (head1 != NULL && head2 != NULL) 
    {
        struct node** smaller = (head1->data <= head2->data) ? &head1 : &head2;
        *tail = *smaller;
        *smaller = (*smaller)->next;
        tail = &((*tail)->next);
    }

    *tail = (head1 != NULL) ? head1 : head2;
}

//Function to Display the List
void List::display() 
{
    if (head == NULL)
    {
        printf("The List is empty \n");
    } 
    else 
    {
        struct node* temp = head;
        while (temp->next != NULL) 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

#endif
