#include <stdio.h>
void main()
{
    int i, n, at[100], bt[100], ct, wt, tt, w_avg, t_avg;
    printf("Enter the no. of processes:");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    ct = 0;
    wt = 0;
    tt = 0;
    for (i = 0; i < n; i++)
    {
        ct += bt[i];
        wt += ct - at[i] - bt[i];
        tt += ct - at[i];
    }
    w_avg = wt / n;
    t_avg = tt / n;
    printf("Avg. waiting time is %d \n", w_avg);
    printf("Avg. turnaround time is %d \n", t_avg);
}