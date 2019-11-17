#include <stdio.h>
void main()
{
    int n = 0, i = 0, head = 0, sum = 0;
    float o = 0.0, k = 5.0;
    int p[20];
    printf("Enter the no .of inputs");
    scanf("%d", &n);
    printf("Enter the inputs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the head position:");
    scanf("%d", &head);
    sum = head - p[0];
    for (i = 0; i < n - 1; i++)
    {
        sum += p[i + 1] > p[i] ? p[i + 1] - p[i] : p[i] - p[i + 1];
    }
    printf("Total Seek time= %d\n", sum);
    o = sum;
    o = o / k;
    printf("Avg Seek time= %f", o);
}