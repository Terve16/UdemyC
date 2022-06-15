#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

float *createArray(const unsigned int length, const float value)
{
    float *data = (float *)malloc(length * sizeof(float));

    if (data == NULL)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < length; i++)
    {
        data[i] = value;
    }

    return data;
}

float *freeArray(float *array)
{
    if (array == NULL)
    {
        return NULL;
    }

    free(array);

    return NULL;
}

Vector *createVector(const unsigned int length, const float value)
{
    Vector *result = (Vector *)malloc(sizeof(Vector));

    if (result == NULL)
    {
        return NULL;
    }

    result->data = createArray(length, value);

    if (result->data == NULL)
    {
        free(result);
        return NULL;
    }

    result->length = length;

    return result;
}

Vector *freeVector(Vector *vector)
{
    if (vector == NULL)
    {
        return NULL;
    }

    if (vector->data != NULL)
    {
        free(vector->data);
        vector->data = NULL;
    }

    free(vector);

    return NULL;
}

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

int readInVectorData(Vector *vec, const char *filepath)
{
    if (vec == NULL || filepath == NULL)
    {
        return 1;
    }

    FILE *fp = fopen(filepath, "r");

    if (fp == NULL)
    {
        return 1;
    }

    for (unsigned int i = 0; i < vec->length; i++)
    {
        fscanf(fp, "%f", &vec->data[i]);
    }

    fclose(fp);
    fp = NULL;

    return 0;
}

int writeOutVectorData(Vector *vec, const char *filepath)
{
    if (vec == NULL || filepath == NULL)
    {
        return 1;
    }

    FILE *fp = fopen(filepath, "w");

    if (fp == NULL)
    {
        return 1;
    }

    for (unsigned int i = 0; i < vec->length; i++)
    {
        if (i < vec->length - 1)
        {
            fprintf(fp, "%f\n", vec->data[i]);
        }
        else
        {
            fprintf(fp, "%f", vec->data[i]);
        }
    }

    fclose(fp);
    fp = NULL;

    return 0;
}

void printVector(const Vector *vector)
{
    if (vector->data == NULL)
    {
        return;
    }

    for (unsigned int i = 0; i < vector->length; i++)
    {
        printf("%f\n", vector->data[i]);
    }

    printf("\n");
}

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Vector *addVectors(const Vector *vec1, const Vector *vec2)
{
    if (vec1 == NULL || vec2 == NULL || vec1->data == NULL || vec2->data == NULL || vec1->length != vec2->length)
        return NULL;

    Vector *v_sum = createVector(vec1->length, 0);

    if (v_sum == NULL)
        return NULL;

    for (unsigned int i = 0; i < vec1->length; i++)
    {
        v_sum->data[i] = (vec1->data[i] + vec2->data[i]);
    }

    return v_sum;
}

Vector *subVectors(const Vector *vec1, const Vector *vec2)
{
    if (vec1 == NULL || vec2 == NULL || vec1->data == NULL || vec2->data == NULL || vec1->length != vec2->length)
        return NULL;

    Vector *v_diff = createVector(vec1->length, 0);

    if (v_diff == NULL)
        return NULL;

    for (unsigned int i = 0; i < vec1->length; i++)
    {
        v_diff->data[i] = (vec1->data[i] - vec2->data[i]);
    }

    return v_diff;
}

float multiplyVectors(const Vector *vec1, const Vector *vec2)
{
    if (vec1 == NULL || vec2 == NULL || vec1->data == NULL || vec2->data == NULL || vec1->length != vec2->length)
        return 0.0f;

    float prod = 0.0f;

    for (unsigned int i = 0; i < vec1->length; i++)
    {
        prod += (vec1->data[i] * vec2->data[i]);
    }

    return prod;
}

Vector *multiplyScalar(const Vector *vec, const float scalar)
{
    if (vec == NULL || vec->data == NULL)
        return NULL;

    Vector *v_prod = createVector(vec->length, 0);

    if (v_prod == NULL)
        return NULL;

    for (unsigned int i = 0; i < vec->length; i++)
    {
        v_prod->data[i] = (vec->data[i] * scalar);
    }

    return v_prod;
}

Vector *divideScalar(const Vector *vec, const float scalar)
{
    if (vec == NULL || vec->data == NULL || scalar == 0.0f) // division with 0 not possible
        return NULL;

    Vector *v_quot = createVector(vec->length, 0);

    if (v_quot == NULL)
        return NULL;

    for (unsigned int i = 0; i < vec->length; i++)
    {
        v_quot->data[i] = (vec->data[i] / scalar);
    }

    return v_quot;
}

float meanVector(const Vector *vector)
{
    float sum = 0.0f;

    for (unsigned int i = 0; i < vector->length; i++)
    {
        sum += vector->data[i];
    }

    return (sum / vector->length);
}

float minVector(const Vector *vector)
{
    if (vector->length == 0)
    {
        return FLT_MAX;
    }

    float current_min = vector->data[0];

    for (unsigned int i = 1; i < vector->length; i++)
    {
        if (vector->data[i] < current_min)
        {
            current_min = vector->data[i];
        }
    }

    return current_min;
}

float maxVector(const Vector *vector)
{
    if (vector->length == 0)
    {
        return FLT_MIN;
    }

    float current_max = vector->data[0];

    for (unsigned int i = 1; i < vector->length; i++)
    {
        if (vector->data[i] > current_max)
        {
            current_max = vector->data[i];
        }
    }

    return current_max;
}
