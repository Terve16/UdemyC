#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Calloc
    int length = 4;
    int *arr = (int *)calloc(length, sizeof(int));

    for (int i = 0; i < length; i++)
    {
        // arr[i] = i;
        printf("%d\n", arr[i]);
    }

    printf("\n");

    // Realloc
    length = 6;
    arr = (int *)realloc(arr, length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        // arr[i] = i;
        printf("%d\n", arr[i]);
    }

    return 0;
}
