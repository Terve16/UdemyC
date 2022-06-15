#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(const void *elem1, const void *elem2)
{
    int l = *((int *)elem1);
    int r = *((int *)elem2);

    if (l > r)
        return 1;
    if (r > l)
        return -1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Please insert file path as first and file lenght as second argument.\n\n");
        return 0;
    }

    char *file_path = argv[1];
    int file_length = atoi(argv[2]);

    if (file_length <= 0)
    {
        printf("Please insert valid file lenght as second argument.\n\n");
        return 0;
    }

    FILE *fp_write = fopen(file_path, "r");

    if (fp_write == NULL)
    {
        printf("Please insert valid file path as first argument.\n\n");
        return 0;
    }

    int *data = (int *)malloc(file_length * sizeof(int));

    if (data == NULL)
    {
        printf("Memory allocation error.\n\n");
        return 0;
    }

    // char string[12] = {'\0'}; // length 12 should be enough for 4 byte uint, 4’294’967’295

    for (unsigned int i = 0; i < ((unsigned int)file_length); i++)
    {
        fscanf(fp_write, "%d", &data[i]);
    }

    qsort(data, file_length, sizeof(int), comp);

    fp_write = freopen(file_path, "w", fp_write);

    if (fp_write == NULL)
    {
        printf("Open file error.\n\n");
        free(data);
        data = NULL;
        return 0;
    }

    for (unsigned int i = 0; i < ((unsigned int)file_length); i++)
    {
        fprintf(fp_write, "%d\n", data[i]);
    }

    free(data);
    data = NULL;

    fclose(fp_write);
    fp_write = NULL;

    return 0;
}
