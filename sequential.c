#include <stdio.h>

int file_system[100] = {0};
int size = 100;

int allocFile(int start_point, int lenght);
void showSpace();

int main()
{
    int start_point, length, is_alloc = 1;

    printf("Enter total available blocks: ");
    scanf("%d", &size);

    while (is_alloc)
    {
        printf("Enter starting block and length of the file : ");
        scanf("%d %d", &start_point, &length);

        if(allocFile(start_point, length)){
            printf("\nFile is allocated\n");
        }else{
            printf("\nFile cannot be allocated!\n");
        }

        showSpace();

        printf("\nType 0 if you want to stop allocation Or Type 1 if you want to add another allocation:\n");
        scanf("%d", &is_alloc);
    }
    return 0;
}

int allocFile(int start_point, int length)
{
    int i;

    if(size < start_point+length)
    {
        printf("File size is exceeding free space");
        return 0;
    }

    for (i = start_point; i < start_point+length; i++)
    {
        if(file_system[i] == 0)
        {
            file_system[i] = 1;
        }
        else{
            return 0;
        }
    }

    return 1;
}

void showSpace()
{
    int i;
    printf("\nDisk: ");
    printf("\n[");
    for (i = 0; i < size; i++)
    {
        printf("%d, ", file_system[i]);
    }

    printf("]\n\n");
}