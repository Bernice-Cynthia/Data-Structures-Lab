//Menu driven program to implement CIRCULAR QUEUE using array

#include <cstdio>
#include <cstdlib>

class QUEUE
{
        int arr[5];
        int front;
        int rear;
    public:
        QUEUE()
        {
            arr[0] = -1;
            arr[1] = -1;
            arr[2] = -1;
            arr[3] = -1;
            arr[4] = -1;
            front = -1;
            rear = -1;
        }
        int enqueue(int);
        int dequeue();
        int peek();
};

int main()
{
    QUEUE obj;
    int chc, num, out;
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
                out = obj.enqueue(num);
                if (out == 0)
                {
                    printf("The QUEUE is full. \n");
                }
                else 
                {
                    printf("Successfully added element. \n");
                }
                break;
            case 2:
                out = obj.dequeue();
                if (out == -1)
                {
                    printf("The QUEUE is empty. \n");
                }
                else 
                {
                    printf("Successfully removed element %d. \n", out);
                }
                break;
            case 3:
                out = obj.peek();
                if (out == -1)
                {
                    printf("The QUEUE is empty \n");
                }
                else
                {
                    printf("%d \n", out);
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
int QUEUE::enqueue(int num)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[0] = num;
        return 1;
    }
    if ((rear + 1)%5 ==  front)
    {
        return 0;
    }
    rear = (rear+1)%5;
    arr[rear] = num;
    return 1;
}

//Function to Dequeue
int QUEUE::dequeue()
{
    if (front == -1 && rear == -1)
    {
        return -1;
    }
    int data = arr[front];
    arr[front] = -1;
    if (rear == front)
    {
        front = -1;
        rear = -1;
        return data;
    }
    front = (front + 1)%5;
    return data;
}

//Function to Peek
int QUEUE::peek()
{
    if (front == -1)
    {
        return -1;
    }
    return arr[front];
}
