// Menu-driven program to sort a given array in ascending order and search for an element

#include <cstdio>
#include <cstdlib>
#include "sort.h"

int linear(int*, int, int);
int binary(int*, int, int);

int main()
{
    int chc, num, len, sea;

    while (1)
    {
        printf("\nMENU\n");
        printf("1.Linear Search \n2.Binary Search \n3.Exit");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &chc);
        if (chc==3)
        {
            exit(0);
        }

        printf("Enter the number of elements: ");
        scanf("%d", &len);
        int arr[len];
        for (int i = 0; i<len; i++)
        {
            printf("Enter element %d: ", i+1);
            scanf("%d", &arr[i]);
        }
        
        printf("Enter the number to be searched: ");
        scanf("%d", &sea);
        switch (chc)
        {
            case 1:
                num = linear(arr, sea, len);
                if (num == -1)
                {
                    printf("The number is not in the array");
                }
                else 
                {
                    printf("The number is found by Linear Search");
                    printf("The number is found at %d index", num);
                }
                break;

            case 2:
                num = binary(arr, sea, len);
                if (num == -1)
                {
                    printf("The number is not in the array");
                }
                else 
                {
                    printf("The number is found by Binary Search");
                    printf("The number is found at %d index", num);
                }
                break;

            case 3:
                exit(0);
        }
    }
    return 0;
}

//Function to linear search
int linear(int arr[], int sea, int len)
{
    for (int i = 0; i<len; i++)
    {
        if (sea == arr[i])
        {
            return i;
        }
    }
    return -1;
}

//Function to binary search
int binary(int arr[], int sea, int len)
{
    bubble(arr, len);
    int low = 0;
    int upp = len - 1;
    int mean = (upp+low)/2;
    while (low <= upp)
    {
        mean = (upp + low)/2;
        if (arr[mean] == sea)
        {
            return mean;
        }
        else if (arr[mean] > sea)
        {
            upp = mean - 1;
        }
        else
        {
            low = mean + 1;
        }
    }
    return -1;
}
