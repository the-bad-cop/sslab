#include <stdio.h>
#include <stdlib.h>
int signal(int);
int wait(int);
void producer();
void consumer();
int buffer, empty, full = 0, mutex = 1;
void main()
{
    printf("Enter the buffer size:");
    scanf("%d", &buffer);
    empty = buffer;
    int choice;
    while (1)
    {
        printf("Enter choice:: 1:Produce 2:Consume 3:Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
                printf("Buffer full!\n");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
                printf("Buffer empty!\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid selection!\n");
        }
    }
}

int signal(int a)
{
    return ++a;
}

int wait(int a)
{
    return --a;
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    printf("Item produced\n");
    empty = wait(empty);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    empty = signal(empty);
    printf("Item consumed\n");
    full = wait(full);
    mutex = signal(mutex);
}