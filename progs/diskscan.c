#include <stdio.h>
void sort(int *, int);
void main()
{
    int i, j, insertpoint, track[5], len = 5, cyl = 0, tkc = 0, head = 0;
    printf("Enter head position: ");
    scanf("%d", &head);
    printf("Enter number of cylinders:");
    scanf("%d", &cyl);
    cyl = cyl - 1;
    printf("Enter no. of inputs: ");
    scanf("%d", &len);
    printf("Enter inputs:\n");
    for (i = 0; i < len; i++)
        scanf("%d", track + i);
    sort(track, len);
    insertpoint = len;
    for (i = 0; i < len; i++)
    {
        if (track[i] >= head)
        {
            insertpoint = i - 1;
            break;
        }
    }
    if (insertpoint < 0)
    {
        tkc = track[len - 1] - head;
    }
    else
    {
        tkc = cyl - head;
        tkc += cyl - track[0];
    }
    printf("Total seek time: %d\n", tkc);
    printf("avg seek time: %f\n", tkc / (float)len);
}
void sort(int *track, int len)
{
    int i, j, min, temptrack, temptime;
    for (i = 0; i < len; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (track[min] > track[j])
                min = j;
        }
        temptrack = track[min];
        track[min] = track[i];
        track[i] = temptrack;
    }
}
