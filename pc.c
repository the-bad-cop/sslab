#include <stdio.h>
#include <stdlib.h>
int mutex = 1, buffer, empty, full = 0, choice;
void main()
{
    int wait(int);
    int signal(int);
    void producer();
    void consumer();
    printf("Enter the buffer size:");
    scanf("%d", &buffer);
    empty = buffer;
    while (1)
    {
        printf("Enter your choice:: 1:Producer 2:Consumer 3:Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            //producer
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("Buffer full!\n");
            }

            break;
        case 2:
            //consumer
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("Buffer empty!\n");
            }
            break;
        case 3:
            exit(0);
            break;
            // default:
            // break;
        }
    }
}
int wait(int s)
{
    return --s;
}
int signal(int s)
{
    return ++s;
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("Produced\n");
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumed\n");
    mutex = signal(mutex);
}