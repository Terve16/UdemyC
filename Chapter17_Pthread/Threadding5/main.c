#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define NUM_THREADS 10
#define NUM_ITERATIONS 100000
//#define USE_MUTEX
#define EXPECTED_RESULT (NUM_THREADS * NUM_ITERATIONS)

int32_t global_counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *function(void *args)
{
    const int32_t arg_i = *((int32_t *)args);

    //printf("Argument: %d\n", arg_i);

    int32_t *result = (int *)malloc(sizeof(int));

    if (result == NULL)
        return NULL;

    *result = arg_i * 2;

    for (int32_t i = 0; i < NUM_ITERATIONS; i++)
    {
#ifdef USE_MUTEX
        pthread_mutex_lock(&mutex);
        global_counter++;
        pthread_mutex_unlock(&mutex);
#else
        global_counter++;
#endif
    }

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
        //printf("Result%d: %d\n", i, *results[i]);
        free(results[i]);
        results[i] = NULL;
    }

    printf("%d\n", global_counter);

    assert(EXPECTED_RESULT == global_counter);

    return 0;
}
