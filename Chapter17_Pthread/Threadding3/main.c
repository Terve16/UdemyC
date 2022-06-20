#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

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
    pthread_t thread1;
    pthread_t thread2;

    int32_t input1 = 1;
    int32_t input2 = 2;

    pthread_create(&thread1, NULL, &function, (void *)&input1);
    pthread_create(&thread2, NULL, &function, (void *)&input2);

    int *result1;
    int *result2;

    pthread_join(thread1, ((void *)&result1));
    pthread_join(thread2, (void *)&result2);

    printf("Result1: %d\n", *result1);
    printf("Result2: %d\n", *result2);

    free(result1);
    free(result2);

    return 0;
}
