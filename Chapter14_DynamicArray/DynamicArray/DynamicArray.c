#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

/****************************/
/* FUNCTIONS                */
/****************************/

void clearDynamicArray(dynamic_array_t *array)
{
    if (!array)
        return;

    if (array->data != NULL)
    {
        free(array->data);
        array->data = NULL;
    }

    free(array);
}

dynamic_array_t *createDynamicArray()
{
    dynamic_array_t *array = (dynamic_array_t *)malloc(sizeof(dynamic_array_t));

    if (!array)
        return NULL;

    array->length = 0;
    array->capacity = INIT_CAPACITY;

    array->data = (float *)malloc(array->capacity * sizeof(float));

    if (!array->data)
    {
        free(array);
        return NULL;
    }

    return array;
}

void expandDynamicArray(dynamic_array_t *array)
{
    if (array == NULL || array->data == NULL)
        return;

    array->capacity += INIT_CAPACITY;
    array->data = realloc(((void *)array->data), (array->capacity * sizeof(float)));

    if (array->data == NULL)
        clearDynamicArray(array);
}

void shrinkDynamicArray(dynamic_array_t *array)
{
    if (array == NULL || array->data == NULL)
        return;

    if (array->capacity > INIT_CAPACITY) // only shrink if it is bigger than min
    {
        array->capacity -= INIT_CAPACITY;
        array->data = realloc(((void *)array->data), (array->capacity * sizeof(float)));
    }

    if (array->data == NULL)
        clearDynamicArray(array);
}

void pushValue(dynamic_array_t *array, float value)
{
    if (array == NULL || array->data == NULL)
        return;

    if (array->length >= array->capacity)
    {
        expandDynamicArray(array);
        if (array == NULL)
            return;
    }

    array->length++;
    array->data[array->length - 1] = value; // no of elements - 1 == index
}

void popValue(dynamic_array_t *array)
{
    if (array == NULL || array->data == NULL)
        return;

    array->data[array->length - 1] = 0.0f; // no of elements - 1 == index
    array->length--;

    if (array->length < (array->capacity - INIT_CAPACITY))
    {
        shrinkDynamicArray(array);
        if (array == NULL)
            return;
    }
}

void printDynamicArray(dynamic_array_t *array)
{
    if (array == NULL || array->data == NULL)
        return;

    printf("\n");
    for (unsigned int i = 0; i < array->length; i++)
    {
        printf("%f\n", array->data[i]);
    }
    printf("\n");
}
