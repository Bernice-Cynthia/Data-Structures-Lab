//Menu-driven program using List ADT of size 5 for List ADT functions

#include <cstdio>
#include <cstdlib>

class List
{
    int arr[5];
    int current;
    public:
        List()
        {
            arr[0] = -1;
            arr[1] = -1;
            arr[2] = -1;
            arr[3] = -1;
            arr[4] = -1;
            current = -1;
        }
        int insbeg(int);
        int insend(int);
        int inspos(int, int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
        void rotate(int);
};

int main()
{
    List obj;
    int chc, num, out;
    while (1)
    {
        printf("\nMENU\n ");
        printf("1. Insertion at Beginning  \n 2. Insertion at End \n 3. Insertion at Position \n ");
        printf("4. Deletion at Beginning  \n 5. Deletion at End \n 6. Deletion at Position \n ");
        printf("7. Search \n 8. Display \n 9. Rotate \n10. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &chc);

        switch (chc)
        {
            case 1:
                printf("Enter number to be inserted at beginning: ");
                scanf("%d", &num);
                out = obj.insbeg(num);
                if (out == 1)
                {
                    printf("The number has been successfully inserted at the beginning. \n");
                }
                else 
                {
                    printf("The List is full. \n");
                }
                break;
            case 2:
                printf("Enter number to be inserted at end: ");
                scanf("%d", &num);
                out = obj.insend(num);
                if (out == 1)
                {
                    printf("The number has been successfully inserted at the end. \n");
                }
                else 
                {
                    printf("The List is full. \n");
                }
                break;
            case 3:
                int pos;
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter number to be inserted at position: ");
                scanf("%d", &num);
                out = obj.inspos(num, pos);
                if (out == 1)
                {
                    printf("The number has been successfully inserted at the position. \n");
                }
                else if (out == -1)
                {
                    printf("The List is full. \n");
                }
                else 
                {
                    printf("Invalid position. \n");
                }
                break;
            case 4:
                out = obj.delbeg();
                if (out == 1)
                {
                    printf("The number has been successfully deleted at the beginning. \n");
                }
                else 
                {
                    printf("The List is empty. \n");
                }
                break;
            case 5:
                out = obj.delend();
                if (out == 1)
                {
                    printf("The number has been successfully deleted at the end. \n");
                }
                else 
                {
                    printf("The List is empty. \n");
                }
                break;
            case 6:
                printf("Enter position to be deleted from: ");
                scanf("%d", &num);
                out = obj.delpos(num);
                if (out == 1)
                {
                    printf("The number has been successfully inserted at the end. \n");
                }
                else 
                {
                    printf("The List is empty. \n");
                }
                break;
            case 7:
                printf("Enter the number you want to search:");
                scanf("%d", &num);
                out = obj.search(num);
                if (out < 0)
                {
                    printf("The given number does not exist in the list. \n");
                }
                else
                {
                    printf("The given number is found at index %d. \n", out);
                }
                break;
            case 8:
                obj.display();
                break;
            case 9:
                printf("Enter number of rotations: ");
                scanf("%d", &num);
                obj.rotate(num);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

//Function to insert at beginning
int List::insbeg(int num)
{
    if(current==4)
    {
        printf("The List is full\n");
        return 0;
    }
    else if(current==-1)
    {
        arr[0]=num;
        current=0;
        return 1;
    }
    current++;
    for(int i = current;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=num;
    return 1;
}

//Function to insert at end
int List::insend(int num)
{
    if (current == 4)
    {
        return -1;
    }
    if (current == -1)
    {
        arr[0] = num;
        current++;
        return 1;
    }
    for (int i=0; i <= current; i++)
    {
        if (i == current)
        {
            arr[i+1] = num;
            current++;
            return 1;
        }
    }
    return 0;
}

//Function to insert at position
int List::inspos(int num, int pos)
{
    if (pos > 4)
    {
        return 0;
    }
    if (current == 4)
    {
        return -1;
    }
    if (current < pos)
    {
        arr[pos] = num;
        return 1;
    }
    return 0;
}

//Function to delete at beginning
int List::delbeg()
{
    if (current == -1)
    {
        return -1;
    }
    current--;
    for(int i = current;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=-1;
    rotate(++current);
    return 1;
}

//Function to delete at end
int List::delend()
{
    if (current == -1)
    {
        return -1;
    }
    for (int i=0; i <= current; i++)
    {
        if (i == current)
        {
            arr[i] = -1;
            current--;
            return 1;
        }
    }
    return 0;
}

//Function to delete at position
int List::delpos(int pos)
{
    if (pos > 4)
    {
        return 0;
    }
    if (current == 0)
    {
        return -1;
    }
    if (current < pos)
    {
        arr[pos] = -1;
        return 1;
    }
    return 0;
}

//Function to search an element
int List::search(int num)
{
    for (int i=0; i<5; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

//Function to display the List
void List::display()
{
    for (int i=0; i<5; i++)
    {
        printf("%d    ", arr[i]);
    }
    printf("\n");
}

//Function to rotate the list
void List::rotate(int num)
{
    if (current==-1)
    {
        printf("List is empty\n");
    }
    else
    {
        for(int i = 0; i<num; i++)
        {
            int temp=arr[current];
            for(int j = current; j>=0; j--)
            {
                arr[j]=arr[j-1];
            }
            arr[0]=temp;
        }
    }
}
