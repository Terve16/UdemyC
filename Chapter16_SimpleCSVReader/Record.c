#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "Record.h"


void free_pairs(value_pair_t *pairs)
{
    if (pairs == NULL)
        return;

    free(pairs);
    pairs = NULL;
}

value_pair_t *create_pairs(const size_t num_pairs)
{
    value_pair_t *values = (value_pair_t *)malloc(num_pairs * sizeof(value_pair_t));
    return values;
}

void free_records(records_t *records)
{
    if (records == NULL)
        return;

    if (records->values != NULL)
    {
        free_pairs(records->values);
    }

    free(records);
    records = NULL;
}

records_t *create_records()
{
    records_t *records = (records_t *)malloc(sizeof(records_t));
    return records;
}


void print_records(const records_t *const records, const char *const header)
{
    if (records == NULL || records->values == NULL)
        return;


    if (header != NULL)
    {
        printf("Records: %s\n", header);
    }

    for (size_t i = 0; i < records->num_values; ++i)
    {
        printf("%c,%d\n", records->values[i].value_a, records->values[i].value_b);
    }

    printf("\n");
}

int comp_descending(const void *left_v, const void *right_v)
{
    const value_pair_t *const left = ((value_pair_t *)left_v);
    const value_pair_t *const right = ((value_pair_t *)right_v);

    if (left->value_b > right->value_b)
        return -1;
    if (right->value_b > left->value_b)
        return 1;
    else
        return 0;
}

int comp_ascending(const void *left_v, const void *right_v)
{
    const value_pair_t *const left = ((value_pair_t *)left_v);
    const value_pair_t *const right = ((value_pair_t *)right_v);

    if (left->value_b > right->value_b)
        return 1;
    if (right->value_b > left->value_b)
        return -1;
    else
        return 0;
}

void sort_records(const records_t *const records, const sorting_scheme_t sorting_scheme)
{
    if (records == NULL || records->values == NULL)
        return;

    switch (sorting_scheme)
    {
    case SORTING_SCHEME_ASCENDING:
    {
        qsort(records->values, records->num_values, sizeof(value_pair_t), comp_ascending);
        break;
    }

    case SORTING_SCHEME_DESCENDING:
    {
        qsort(records->values, records->num_values, sizeof(value_pair_t), comp_descending);
        break;
    }

    default:
        break;
    }
}
