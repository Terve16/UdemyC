#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = (int *)malloc(sizeof(int));

    *a = 10; // some computations

    printf("%d\n", *a);
    printf("0x%x\n", a);
    free(a);
    printf("0x%x\n", a);
    a = NULL;
    printf("0x%x\n", a);

    if (a != NULL)
        printf("%d\n", *a);

    return 0;
}
