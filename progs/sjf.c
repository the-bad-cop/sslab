#include <stdio.h>
void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void main()
{
    int a[20], b[20], w, t, i, j, c, s, n, tot1 = 0, tot2 = 0;
    float avg1, avg2;
    printf("\nEnter no. of processes = ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Process:%d\n ", i + 1);
        scanf("%d %d", &a[i], &b[i]);
    }
    c = a[0];
    for (i = 0; i < n; i++)
    {
        j = i;
        s = i;
        while (a[j] <= c)
        {
            if (b[s] > b[j])
            {
                s = j;
            }
            j++;
        }
        w = c - a[s];
        tot1 += w;
        t = w + b[s];
        tot2 += t;
        c += b[s];
        swap(a, i, s);
        swap(b, i, s);
    }
    avg1 = (float)tot1 / n;
    avg2 = (float)tot2 / n;
    printf("\nAvg waiting time=%f", avg1);
    printf("\nAvg turn around time=%f", avg2);
}
