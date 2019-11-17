#include <stdio.h>
void main()
{
    int lru[10][10], p, l = 0, i, j, k, a = 0, n, pg = 0, min, min1, in[10];
    printf("Enter the frame size:");
    scanf("%d", &p);
    printf("Enter the no.of pages:");
    scanf("%d", &n);
    printf("Enter the reference string:\n");
    k = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            lru[i][j] = -1;
        }
    }
    while (k < n)
    {
        scanf("%d", &in[k]);
        k++;
    }
    l = 0;
    for (i = 0; i < n; i++)
    {
        a = 0;
        k = 0;
        if (i < p)
        {
            while (k < p)
            {
                if (in[i] == lru[k][0])
                {
                    lru[k][1]++;
                    lru[k][2] = i;
                    a = 1;
                    break;
                }
                k++;
            }
            if (a == 0)
            {
                lru[l][0] = in[i];
                lru[l][1] = 0;
                lru[l++][2] = i;
                pg++;
            }
        }
        else
        {
            while (k < p)
            {
                if (in[i] == lru[k][0])
                {
                    lru[k][1]++;
                    lru[k][2] = i;
                    a = 1;
                    break;
                }
                k++;
            }
            if (a == 0)
            {
                j = 0;
                min = lru[0][1];
                k = 0;
                while (k < p)
                {
                    if (lru[k][1] < min)
                    {
                        min = lru[k][1];
                    }
                    k++;
                }
                k = 0;
                min1 = lru[0][2];
                while (k < p)
                {
                    if (lru[k][2] <= min1 & lru[k][1] == min)
                    {
                        min1 = lru[k][2];
                        l = k;
                    }
                    k++;
                }
                lru[l][0] = in[i];
                lru[l][1] = 0;
                lru[l][2] = i;
                pg++;
            }
        }
    }
    printf("\nThe no of page faults is : %d", pg);
}