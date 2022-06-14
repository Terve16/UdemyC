#include <stdio.h>

#include "Lib.h"

float meanArray(int *array, unsigned int length)
{
    if (length == 0 || array == NULL)
        return 0;

    int sum = 0;

    for (unsigned int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return (float)(sum) / (float)(length);
}

int minArray(int *array, unsigned int length)
{
    if (length == 0 || array == NULL)
        return 0;

    int min = array[0];

    for (unsigned int i = 1; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

int maxArray(int *array, unsigned int length)
{
    if (length == 0 || array == NULL)
        return 0;

    int max = array[0];

    for (unsigned int i = 1; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}


void getUserInput(int *array, unsigned int length, unsigned int *no_of_inputs)
{
    if (length == 0 || array == NULL || no_of_inputs == NULL)
        return;

    printf("Please enter the numbers (Quit by entering negative number): \n");

    for (unsigned int i = 0; i < length; i++)
    {
        int temp;
        scanf("%d", &temp);

        if (temp >= 0)
        {
            array[i] = temp;
        }
        else
        {
            *no_of_inputs = i;
            return;
        }
    }

    *no_of_inputs = length;
    return;
}
