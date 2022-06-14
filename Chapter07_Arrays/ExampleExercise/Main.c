#include <math.h>
#include <stdio.h>

#include "Lib.h"

#define LENGTH 1000

int main()
{
    int v[LENGTH] = {0};

    unsigned int number_of_inputs;
    getUserInput(v, LENGTH, &number_of_inputs);

    int min_v = minArray(v, number_of_inputs);
    int max_v = maxArray(v, number_of_inputs);
    float mean_v = meanArray(v, number_of_inputs);

    printf("Min: %d\n", min_v);
    printf("Max: %d\n", max_v);
    printf("Mean: %f\n", mean_v);

    return 0;
}
