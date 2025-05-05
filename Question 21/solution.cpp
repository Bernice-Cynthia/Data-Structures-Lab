#include <stdio.h>

#define MX 1000

int sim(int n, int a[], int k) 
{
    int p[MX] = {0}; 
    int winners = n;
    while (1) 
    {
        int any_kick = 0;
        for (int i = 0; i < k; i++) 
        {
            int count = 0;
            for (int j = 0; j < n; j++) 
            {
                if (p[j] == 0) 
                { 
                    count++;
                    if (count == a[i]) 
                    { 
                        p[j] = 1; 
                        winners--; 
                        any_kick = 1; 
                        break; 
                    }
                }
            }
        }

        if (!any_kick) break; 
    }

    return winners; 
}

int main() 
{
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    while (t--) 
    {
        int k, q;
        printf("Enter the length of sequence 'a' and the number of queries: ");
        scanf("%d %d", &k, &q);

        int a[k];
        printf("Enter the sequence 'a' (%d integers separated by space): ", k);
        for (int i = 0; i < k; i++) scanf("%d", &a[i]);

        for (int j = 0; j < q; j++) 
        {
            int n;
            printf("Enter the number of players: ");
            scanf("%d", &n);
            printf("Number of winners: %d\n", sim(n, a, k));
        }
    }

    return 0;
}

