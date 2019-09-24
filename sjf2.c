#include <stdio.h>
int at[20], n, bt[20];
int min(int i, int j)
{
    int k, m, a;
    k = i;
    for (m = i; m < j; m++)
    {
        if (bt[m] < bt[k])
            k = m;
    }
    a = bt[i];
    bt[i] = bt[k];
    bt[k] = a;
    return i;
}
void main()
{
    int i, j, k, tot1 = 0, w, c, x, tot2 = 0;
    float avg1, avg2;
    printf("\nnEnter the no. of processes:");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time of all processes:");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &at[i], &bt[i]);
    }
    c = at[0];
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j < n && at[j] <= c)
        {
            j++;
        }
        x = min(i, j);
        printf("\n%d", bt[x]);
        w = c - at[x];
        tot1 += w;
        tot2 += w + bt[x];
        c += bt[x];
    }
    avg1 = (float)tot1 / n;
    avg2 = (float)tot2 / n;
    printf("\nAvg-wt %f  avg_tt %f", avg1, avg2);
}