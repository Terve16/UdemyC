#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define NUM_THREADS 3

typedef struct
{
    int32_t input1;
    int32_t input2;
    int32_t output;
} ThreadData_t;


void *function(void *args)
{
    ThreadData_t *data = (ThreadData_t *)args;

    printf("Argumente: %d, %d\n", data->input1, data->input2);

    data->output = data->input1 * data->input2;

    return NULL;
}


int main()
{
    pthread_t threads[NUM_THREADS] = {NULL};

    ThreadData_t thread_data[NUM_THREADS] = {{.input1 = 0}, {.input2 = 0}, {.output = 0}};

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        thread_data[i].input1 = i;
        thread_data[i].input2 = i * 2;
    }
    /*
    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        printf("%d\n", thread_data[i].output);
    }
    */
    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, &function, (void *)&thread_data[i]);
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (int32_t i = 0; i < NUM_THREADS; i++)
    {
        printf("Result%d: %d\n", i, thread_data[i].output);
    }

    return 0;
}
