#include <stdio.h>
void main()
{
    int f, p, pg[10], pf = 0, i, c, frame[10], j, t = 0, x = 0;
    printf("\nEnter the frame size: ");
    scanf("%d", &f);
    printf("\nEnter the no. of pages: ");
    scanf("%d", &p);
    printf("\nEnter the reference string: \n");
    for (i = 0; i < p; i++)
        scanf("%d", &pg[i]);
    c = 0;
    i = 0;
    while (i < p)
    {
        while (c < f)
        {
            frame[c++] = pg[i++];
            pf++;
        }
        t = 0;
        if (c == f)
        {
            for (j = 0; j < f; j++)
            {
                if (pg[i] == frame[j])
                    t = 1;
            }
            j = x;
            if (t == 0)
            {
                frame[j] = pg[i];
                x++;
                pf++;
                if (x == f)
                    x = 0;
            }
            i++;
        }
    }
    printf("\nThe no. of page faults is:%d\n", pf);
}