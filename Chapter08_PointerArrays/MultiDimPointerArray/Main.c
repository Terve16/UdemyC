#include <stdio.h>
#include <stdlib.h>

int *createArray(unsigned int length, int value)
{
    int *array = (int *)malloc(length * sizeof(int));

    if (array == NULL)
        return NULL;

    for (unsigned int i = 0; i < length; i++)
    {
        array[i] = value;
    }

    return array;
}

int *freeArray(int *array)
{
    if (array == NULL)
        return NULL;

    free(array);
    return NULL;
}

int **freeMatrix(unsigned int no_rows, int **matrix)
{
    if (matrix == NULL)
        return NULL;

    for (unsigned int i = 0; i < no_rows; i++)
    {
        matrix[i] = freeArray(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    return NULL;
}

int **createMatrix(unsigned int no_rows, unsigned int no_columns, int value)
{
    int **matrix = (int **)malloc(no_rows * sizeof(int *));

    if (matrix == NULL)
        return NULL;

    for (unsigned int i = 0; i < no_rows; i++)
    {
        matrix[i] = createArray(no_columns, value);

        if (matrix[i] == NULL) // error, bad alloc
        {
            // free memory and exit function
            matrix = freeMatrix(i, matrix);
            return NULL;
        }
    }


    return matrix;
}


int main()
{
    unsigned int length = 3;

    int *array = createArray(length, 1);

    if (array == NULL)
        return 0;

    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }

    array = freeArray(array);

    printf("%p\n", array);

    int **matrix = createMatrix(2, 3, 1337);

    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            printf("%d\n", matrix[i][j]);
        }
    }

    matrix = freeMatrix(2, matrix);

    return 0;
}
