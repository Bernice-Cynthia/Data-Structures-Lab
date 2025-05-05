//Program for removing duplicate elements

#include <cstdio>
#include <cstdlib>

int main()
{
    int test, size, com;
    printf("Enter no. of testcases: ");
    scanf("%d", &test);

    while (test--)
    {
        printf("Enter size of array: ");
        scanf("%d", &size);
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            printf("Enter element %d: ", i+1);
            scanf("%d", &arr[i]);
        }

        com = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    com = i + 1;
                }
            }
        }

        printf("No. of deleted elements: %d \n", com );
    }
    return 0;
}
