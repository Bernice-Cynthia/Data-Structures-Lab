//Menu driven program to implement QUEUE using array

#include <cstdio>
#include <cstdlib>

class QUEUE
{
        struct node 
        {
            int data;
            struct node *next;
        };
        struct node* front;
        struct node* rear;
    public:
        QUEUE()
        {
            front = NULL;
            rear = NULL;
        }
        void enqueue(int);
        int dequeue();
        int peek();
};

int main()
{
    QUEUE obj;
    int chc, num;
    while(1)
    {
        printf("\nMENU\n ");
        printf("1. Enqueue  \n 2. Dequeue \n 3. Peek \n 4. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &chc);

        switch (chc)
        {
            case 1:
                printf("Enter number to be enqueued: ");
                scanf("%d", &num);
                obj.enqueue(num);
                break;
            case 2:
                num = obj.dequeue();
                if (num == -1)
                {
                    printf("The QUEUE is empty. \n");
                }
                else 
                {
                    printf("Successfully removed element %d. \n", num);
                }
                break;
            case 3:
                num = obj.peek();
                if (num == -1)
                {
                    printf("The QUEUE is empty \n");
                }
                else
                {
                    printf("%d \n", num);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

//Function to Enqueue
void QUEUE::enqueue(int num)
{   
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
        return;
    }
    struct node *temp  = front;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    rear = newnode;
    return;
}

//Function to Dequeue
int QUEUE::dequeue()
{
    if (front == NULL && rear == NULL)
    {
        return -1;
    }
    int data = front->data;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
        return data;
    }
    front = front->next;
    return data;
}

//Function to Peek
int QUEUE::peek()
{
    if (front == NULL)
    {
        return -1;
    }
    return front->data;
}

