#include <stdio.h>
void main()
{
    int n, at[10], bt[10], i, ct[10];
    printf("Enter the no. of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        ct[i] = 0;
    }
    printf("Enter the at and bt of:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process-%d:", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    int wt[10], tt[10], s_tt = 0, s_wt = 0, c = 0;
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1] + at[i - 1];
    }
    for (i = 1; i < n; i++)
    {
        tt[i] = wt[i] + bt[i];
    }

    for (i = 0; i < n; i++)
    {
        s_tt += tt[i];
        s_wt += wt[i];
    }
    printf("Avg. wt is %f and tt is %f", (float)(s_wt / n), (float)(s_tt / n));
}