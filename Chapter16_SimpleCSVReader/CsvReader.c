#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "CsvReader.h"
#include "Record.h"

#define BUFFER_SIZE (size_t)(128)
#define NEW_LINE_CHARACTER_ASCII ('\n')

size_t line_count(const char *const file_path)
{
    if (file_path == NULL)
        return 0;

    FILE *const fp = fopen(file_path, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 0;
    }

    size_t count = 0;
    char temp;

    while (fscanf(fp, "%c", &temp) != EOF)
    {
        if (NEW_LINE_CHARACTER_ASCII == temp)
        {
            ++count;
        }
    }

    fclose(fp);

    return count;
}

void read_simple_csv(const char *const file_path, records_t *const records)
{
    if (file_path == NULL || records == NULL)
        return;

    FILE *const fp = fopen(file_path, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    }

    const size_t num_lines = line_count(file_path);

    value_pair_t *const values = create_pairs(num_lines);

    if (values == NULL)
    {
        fclose(fp);
        return;
    }

    for (size_t i = 0; i < num_lines; ++i)
    {
        char buffer[BUFFER_SIZE] = {'\0'};
        fgets(buffer, BUFFER_SIZE, fp);

        sscanf(buffer, "%c,%d", &values[i].value_a, &values[i].value_b);
    }

    fclose(fp);

    records->values = values;
    records->num_values = num_lines;
}

void write_simple_csv(const char *const file_path, const records_t *const records)
{
    if (file_path == NULL || records == NULL || records->values == NULL)
        return;

    FILE *const fp = fopen(file_path, "w");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    }

    for (size_t i = 0; i < records->num_values; ++i)
    {
        fprintf(fp, "%c,%d\n", records->values[i].value_a, records->values[i].value_b);
    }

    fclose(fp);
}
