#include <stdio.h>
void main()
{
    int n, small, p[20], a[20], w[20], b[20], t[20], g[20], i, j, temp;
    float aww = 0, att = 0;
    printf("Enter number of process==\n");
    scanf("%d", &n);
    printf("Enter burst time==\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    printf("Enter Arrival time==\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter priority==\n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (i = 0; i < n; i++)
    {
        small = i;
        for (j = i; j < n; j++)
        {
            if (p[small] > p[j])
                small = j;
        }
        temp = p[i];
        p[i] = p[small];
        p[small] = temp;
        temp = b[i];
        b[i] = b[small];
        b[small] = temp;
        temp = a[i];
        a[i] = a[small];
        a[small] = temp;
    }
    g[0] = 0;
    for (i = 0; i < n; i++)
        g[i + 1] = g[i] + b[i];
    for (i = 0; i < n; i++)
    {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        aww = aww + w[i];
        att = att + t[i];
    }
    aww = aww / n;
    att = att / n;
    printf("\tARRIVALTIME\tBURSTTIME\tPRIORITY\n\n\n\n\n");
    for (i = 0; i < n; i++)
        printf("\t%d\t\t%d\t\t%d\n\n", a[i], b[i], p[i]);
    printf("Avg Waiting time==%f\n\n", aww);
    printf("Avg Turnaroundtime==%f\n\n", att);
}