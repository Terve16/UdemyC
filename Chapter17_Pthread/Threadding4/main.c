#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define NUM_THREADS 3


void *function(void *args)
{
    const int32_t arg_i = *((int32_t *)args);

    printf("Argument: %d\n", arg_i);

    int32_t *result = (int *)malloc(sizeof(int));

    if (result == NULL)
        return NULL;

    *result = arg_i * 2;

    // return result;
    pthread_exit((void *)result);
}


int main()
{
    pthread_t threads[NUM_THREADS] = {NULL};

    int32_t inputs[NUM_THREADS] = {0};

    int *results[NUM_THREADS] = {NULL};

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        inputs[i] = i;
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, &function, (void *)&inputs[i]);
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], ((void *)&results[i]));
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        printf("Result%d: %d\n", i, *results[i]);
        free(results[i]);
        results[i] = NULL;
    }

    return 0;
}
