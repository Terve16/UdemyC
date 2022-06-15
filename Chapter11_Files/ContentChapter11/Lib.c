#include <stdio.h>
#include <stdlib.h>

#include "Lib.h"

int getNumberFromUser()
{
    int number_from_user; //0x00: 12

    printf("Pls enter a interger number!\n");
    scanf("%d", &number_from_user);

    return number_from_user; // return 12;
}


sVector *freeSVector(sVector *vector)
{
    if (vector == NULL)
        return NULL;

    if (vector->data != NULL)
    {
        free(vector->data);
    }
    vector->data = NULL;

    free(vector);
    vector = NULL;

    return NULL;
}


sVector *createSVector(unsigned int length, char value)
{
    sVector *new_vector = (sVector *)malloc(sizeof(sVector));

    if (new_vector == NULL)
        return NULL;

    new_vector->length = length;
    new_vector->data = (char *)malloc(length * sizeof(int));

    if (new_vector->data == NULL)
    {
        free(new_vector);
        new_vector = NULL;
        return NULL;
    }

    for (unsigned int i = 0; i < length; i++)
    {
        new_vector->data[i] = value;
    }

    return new_vector;
}


void printSVector(sVector *vector)
{
    if (vector == NULL ||
        vector->data == NULL)
    {
        return;
    }

    printf("%s\n", vector->data);

}


sMatrix *freeSMatrix(sMatrix *smatrix)
{
    if (smatrix == NULL)
        return NULL;

    for (unsigned int i = 0; i < smatrix->size; i++)
    {
        if (smatrix->svector[i] != NULL)
        {
            freeSVector(smatrix->svector[i]);
        }
    }

    free(smatrix);
    smatrix = NULL;

    return NULL;
}


sMatrix *createSMatrix(unsigned int size, unsigned int length, char value)
{
    sMatrix *new_matrix = (sMatrix *)malloc(sizeof(sMatrix));

    if (new_matrix == NULL)
        return NULL;

    new_matrix->size = size;

    for (unsigned int i = 0; i < size; i++)
    {
        new_matrix->svector[i] = createSVector(length, value);

        if (new_matrix->svector[i] == NULL)
        {
            for (unsigned int j = 0; j < i; j++)
            {
                new_matrix->svector[i] = freeSVector(new_matrix->svector[i]);
                return NULL;
            }
        }
    }

    return new_matrix;
}



void printSMatrix(sMatrix *smatrix)
{
    if (smatrix == NULL)
        return;

    for (unsigned int i = 0; i < smatrix->size; i++)
    {
        if (smatrix->svector[i] == NULL)
            continue;

        printSVector(smatrix->svector[i]);
    }
}
