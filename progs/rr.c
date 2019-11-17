#include <stdio.h>
int rear = -1, front = -1, que[30];
void enqueue(int item)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear++;
    que[rear] = item;
}
int dequeue()
{
    int item;
    if (front == rear)
    {
        item = que[front];
        front = -1;
        rear = -1;
    }
    else
    {
        item = que[front];
        front++;
    }
    return item;
}
void main()
{
    int a[20], b[20], bt[20], p[20], w, q, i, j, c, n, tot1 = 0, tot2 = 0, s = 0, x;
    float avg1, avg2;
    printf("\nEnter the no. of processes = ");
    scanf("%d", &n);
    printf("\nEnter the processes details(arrival time and burst time):");
    for (i = 0; i < n; i++)
    {
        printf("\nprocess %d = ", i + 1);
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] == a[0])
        {
            enqueue(i);
            bt[i] = 1;
        }
        p[i] = 0;
        s += b[i];
    }
    printf("\nEnter the time quantum = ");
    scanf("%d", &q);
    c = a[0];
    while (c < s)
    {
        x = 0;
        if (front != -1)
        {
            i = dequeue();
            bt[i] = 0;
            if (b[i] <= q)
            {
                w = c - (a[i] + (p[i] * q));
                tot1 += w;
                tot2 += w + (b[i] + p[i] * q);
                x += b[i];
                b[i] = 0;
            }
            else
            {
                p[i]++;
                x += q;
                b[i] -= q;
            }
            j = i + 1;
            while (a[j] <= c + x && j < n)
            {
                if (bt[j] != 1 && b[j] != 0)
                {
                    enqueue(j);
                    bt[j] = 1;
                }
                j++;
            }
            if (b[i] != 0 && bt[i] != 1)
            {
                enqueue(i);
                bt[i] = 1;
            }
            c += x;
            printf("%d \n", c);
        }
        else
        {
            c++;
            s++;
        }
    }
    avg1 = (float)tot1 / n;
    avg2 = (float)tot2 / n;
    printf("\navg waiting time = %f & avg turn around time = %f", avg1, avg2);
}