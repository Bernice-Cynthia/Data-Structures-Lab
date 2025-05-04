// Menu-driven program to sort a given array in ascending order

#include <cstdio>
#include <cstdlib>

void bubble(int* , int );
void selection(int* , int );
void insertion(int* , int );

int main()
{
    int chc, num, len;

    while (1)
    {
        printf("\nMENU\n");
        printf("1.Bubble Sort \n2.Selection Sort \n3.Insertion Sort \n4.Exit \n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &chc);
        if (chc==4)
        {
            exit(0);
        }

        printf("Enter the number of elements: ");
        scanf("%d", &len);
        
        //Creating an array
        int arr[len];
        for (int i = 0; i<len; i++)
        {
            printf("Enter element %d: ", i+1);
            scanf("%d", &arr[i]);
        }

        switch (chc)
        {
            case 1:
                bubble(arr,len);
                printf("The given array has been sorted using Bubble Sort\n");
                printf("The sorted array is: ");
                for (int i = 0; i<len; i++)
                {
                    printf("%d  ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                selection(arr,len);
                printf("The given array has been sorted using Selection Sort\n");
                printf("The sorted array is: ");
                for (int i = 0; i<len; i++)
                {
                    printf("%d  ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                insertion(arr,len);
                printf("The given array has been sorted using Insertion Sort\n");
                printf("The sorted array is: ");
                for (int i = 0; i<len; i++)
                {
                    printf("%d  ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Please enter a valid choice");
        }
    }
    return 0;
}

//Function to sort using bubble sort
void bubble(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Function to sort using selection sort
void selection(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++) 
    {
        int m = i;
        for (int j = i + 1; j < len; j++) 
        {
            if (arr[j] < arr[m])
                m = j;
        }
        int temp = arr[m];
        arr[m] = arr[i];
        arr[i] = temp;
    }
}

//Function to sort using insertion sort
void insertion(int arr[], int len)
{
    for (int i = 1; i < len; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >=0 && key < arr[j]) 
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
