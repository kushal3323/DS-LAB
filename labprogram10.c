#include <stdio.h>

#define MAX 100

int main()
{
    int HT[MAX];
    int m, n;
    int key, index;
    int i, j;


    for (i = 0; i < MAX; i++)
        HT[i] = -1;


    printf("Enter size of hash table (m): ");
    scanf("%d", &m);


    printf("Enter number of employee records (n): ");
    scanf("%d", &n);


    for (i = 0; i < n; i++)
    {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);

        index = key % m;


        if (HT[index] == -1)
        {
            HT[index] = key;
        }
        else
        {
            j = (index + 1) % m;
            while (HT[j] != -1)
            {
                j = (j + 1) % m;
            }
            HT[j] = key;
        }
    }


    printf("\nHash Table:\n");
    printf("Address  Key\n");
    for (i = 0; i < m; i++)
    {
        if (HT[i] != -1)
            printf("%2d     %d\n", i, HT[i]);
        else
            printf("%2d     --\n", i);
    }

    return 0;
}

