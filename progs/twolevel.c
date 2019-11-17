#include <stdio.h>
#include <string.h>
typedef struct user
{
    int g;
    char name[10];
    char dir[10];
    char files[10][10];
} User;
void main()
{
    User users[10];
    int g = 0, i = 0, j = 0, n, m, z;
    char null[1] = {'\0'};
    char temp[10];
    void afterlogin(int id)
    {
        void display()
        {
            printf("\n The files in directory %s are:\n ", users[id].dir);
            i = 0;
            while (i < users[id].g)
            {
                printf("%s\n", users[id].files[i]);
                i++;
            }
        }
        void create()
        {
            printf("Enter the file name ");
            scanf("%s", temp);
            i = 0;
            while (i < 10)
            {
                m = strcmp(temp, users[id].files[i]);
                if (m == 0)
                {
                    printf("\nFile exists!\n");
                    return;
                }
                i++;
            }
            j = users[id].g++;
            strcpy(users[id].files[j], temp);
            printf("File created\n");
            // display();
        }
        void search()
        {
            i = 0;
            printf("\nEnter the filename\n");
            scanf("%s", temp);
            while (i < 10)
            {
                m = strcmp(temp, users[id].files[i]);
                if (m == 0)
                {
                    printf("\nFile found\n");
                    return;
                }
                i++;
            }
            printf("\nFile not Found\n");
            return;
        }
        void delete ()
        {
            i = 0;
            printf("\nEnter the filename to delete\n");
            scanf("%s", temp);
            while (i < 10)
            {
                m = strcmp(temp, users[id].files[i]);
                if (m == 0)
                {
                    strcpy(users[id].files[i], null);
                    printf("\nFile deleted\n");
                    return;
                }
                i++;
            }
            printf("\nFile not Found\n");
            return;
        }
        while (1)
        {
            printf("Choose an option:\n");
            printf("1.Create file\n2.Search file\n3.Delete file\n4.Display files\n5.Go back\n");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                create();
                break;
            case 2:
                search();
                break;
            case 3:
                delete ();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("\nEnter a valid option\n");
                break;
            }
            if (n == 5)
            {
                break;
            }
        }
        printf("\n");
    }
    void createUser()
    {
        printf("Enter the username: ");
        scanf("%s", temp);
        strcpy(users[g].name, temp);
        users[g].g = 0;
        printf("Enter the dirname for %s: ", temp);
        scanf("%s", temp);
    }
    void login()
    {
        printf("Enter the username: ");
        scanf("%s", temp);
        i = 0;
        while (i < 10)
        {
            int m = strcmp(users[i].name, temp);
            if (m == 0)
            {
                afterlogin(i);
                return;
            }
            i++;
        }
        printf("\nInvalid username!\n");
        return;
    }
    while (1)
    {
        printf("Choose an option:\n");
        printf("1.Create User\n2.Go to User\n5.Exit\n");
        scanf("%d", &z);
        switch (z)
        {
        case 1:
            createUser();
            break;
        case 2:
            login();
            break;
        default:
            printf("\nEnter a valid option!\n");
            break;
        }
        if (z == 5)
        {
            break;
        }
    }
}