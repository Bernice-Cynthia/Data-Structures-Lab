#include <cstdio>
#include <cstdlib>

int main()
{
    int test, num, max, max2;
    printf("Enter no. of testcases: ");
    scanf("%d", &test);

    while (test--)
    {
        max = 0;
        max2 = 0;
        printf("Enter no. of elements: ");
        scanf("%d", &num);
        int arr[num];
        int res[num];
        for (int i = 0;i < num; i++)
        {
            printf("Enter elememt %d: ", i+1);
            scanf("%d", &arr[i]);
            if (arr[i] > max)
            {
                max = arr[i];
            }
            if (arr[i] > max2 && arr[i] < max)
            {
                max2 = arr[i];
            }
        }
        for (int i = 0;i < num; i++)
        {
            if (arr[i] == max)
            {
                res[i] = max - max2;
            }
            else
            {
                res[i] = arr[i] - max;
            }
        }
        printf("max = %d %d\n", max, max2);
        for (int i = 0;i < num; i++)
        {
            printf("%d  ", res[i]);
        }
        printf("\n");
    }
    return 0;
}
