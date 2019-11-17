#include <stdio.h>
void main()
{
    int n, head, temp = 0, i = 0, j = 0, total = 0, cyl, p[100];
    // int p[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    float o, k;
    printf("Enter head position:");
    scanf("%d", &head);
    printf("Enter no. of cylinders:");
    scanf("%d", &cyl);
    printf("Enter no. of inputs:");
    scanf("%d", &n);
    printf("Enter inputs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i] < p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (p[i] > head)
        {
            break;
        }
    }
    total = (cyl - 1 - head) + p[i - 1];
    printf("Seek time %d", total);
    k = n;
    o = total;
    o = o / k;
    printf(" Avg Seek time= %f", o);
}