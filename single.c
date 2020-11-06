#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct
{
    char dname[10], fname[10][10];
    int fcnt;
} dir;

void main()
{
    int i, ch;
    char f[30];
    dir.fcnt = 0;
    printf("\nEnter name of directory:");
    scanf("%s", dir.dname);
    while (1)
    {
        printf("\n1. Create File\t2. Delete File\t3. Search File \t4. Display Files\n5. Exit\n\nEsnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the name of the file:");
            scanf("%s", dir.fname[dir.fcnt]);
            dir.fcnt++;
            break;
        case 2:
            printf("\nEnter the name of the file: ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is deleted\n", f);
                    strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("File %s not found\n", f);
            else
                dir.fcnt--;
            break;
        case 3:
            printf("\nEnter the name of the file:");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is found\n", f);
                    break;
                }
            }
            if (i == dir.fcnt)
                printf("File %s not found\n", f);
            break;
        case 4:
            if (dir.fcnt == 0)
                printf("\nDirectory Empty");
            else
            {
                printf("\nThe Files are:");
                for (i = 0; i < dir.fcnt; i++)
                    printf("\t%s", dir.fname[i]);
                printf("\n");
            }
            break;
        default:
            exit(0);
        }
    }
}