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

void printArray(int *array, unsigned int length)
{
    if (array == NULL)
        return;

    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }
}

unsigned int index_lookup(unsigned int i, unsigned int j, unsigned int num_columns)
{
    return (i * num_columns + j);
}

void printMatrix(int *matrix, unsigned int no_rows, unsigned int no_columns)
{
    if (matrix == NULL)
        return;

    for (unsigned int i = 0; i < no_rows; i++)
    {
        for (unsigned int j = 0; j < no_columns; j++)
        {
            printf("%d, ", matrix[index_lookup(i, j, no_columns)]);
        }
        printf("\n");
    }
    printf("\n");
}




int main()
{
    unsigned int num_rows = 2;
    unsigned int num_columns = 3;
    unsigned int num_elements = 6;

    int *array = createArray(num_elements, 1);

    if (array == NULL)
        return 0;

    printMatrix(array, num_rows, num_columns);

    array = freeArray(array);

    return 0;
}
