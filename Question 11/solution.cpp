// Program to implement stack using an array of size 5

#include <cstdio>
#include <cstdlib>

class Stack
{
    char arr[5];
    int top;
public:
    Stack()
    {
        top = -1;
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
    if(top == 4)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        arr[top] = val;
    }
}

//Function to Pop (To remove the top element in the stack)
void Stack::Pop()
{
    if(top == -1)
    {
        printf("The stack is empty\n");
        return;
    }
    char pop = arr[top];
    top --;
}

//Function to Peek (To see the top element in the stack)
void Stack::Peek()
{
    if(top == -1)
    {
        printf("The stack is empty\n");
        return;
    }
    printf("The top element is %c", arr[top]);
}

