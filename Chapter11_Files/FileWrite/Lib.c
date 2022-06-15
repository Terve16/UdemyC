#include <stdio.h>
#include <stdlib.h>

#include "Lib.h"


Vector *freeVector(Vector *vector)
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


Vector *createVector(unsigned int length, int value)
{
    Vector *new_vector = (Vector *)malloc(sizeof(Vector));

    if (new_vector == NULL)
        return NULL;

    new_vector->length = length;
    new_vector->data = (int *)malloc(length * sizeof(int));

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


float meanVector(Vector *vector)
{
    if (vector->length == 0)
        return 0.0f;

    int sum = 0;

    for (unsigned int i = 0; i < vector->length; i++)
    {
        sum += vector->data[i];
    }

    return (float)(sum) / (float)(vector->length);
}

int minVector(Vector *vector)
{
    if (vector->length == 0)
    {
        return 0;
    }

    int current_min = vector->data[0];

    for (unsigned int i = 1; i < vector->length; i++)
    {
        if (vector->data[i] < current_min)
        {
            current_min = vector->data[i];
        }
    }

    return current_min;
}

int maxVector(Vector *vector)
{
    if (vector->length == 0)
    {
        return 0;
    }

    int current_max = vector->data[0];

    for (unsigned int i = 1; i < vector->length; i++)
    {
        if (vector->data[i] > current_max)
        {
            current_max = vector->data[i];
        }
    }

    return current_max;
}

void printVector(Vector *vector)
{
    if (vector->data == NULL)
    {
        return;
    }

    for (unsigned int i = 0; i < vector->length; i++)
    {
        printf("%d\n", vector->data[i]);
    }
}
