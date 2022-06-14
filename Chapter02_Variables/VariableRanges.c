#include <float.h>
#include <limits.h>
#include <stdio.h>

int main()
{
    int a = -11;
    unsigned int b = 1u;
    float c = 1.0f;
    double d = 1.0;
    char e = 42;
    short f = 87;

    printf("Variable a: %lu\n", sizeof(a));
    printf("Variable b: %lu\n", sizeof(b));
    printf("Variable c: %lu\n", sizeof(c));
    printf("Variable d: %lu\n", sizeof(d));
    printf("Variable e: %lu\n", sizeof(e));
    printf("Variable f: %lu\n", sizeof(f));

    printf("Int range: %d, %d\n", INT_MIN, INT_MAX);
    printf("Float range: %E, %E\n", FLT_MIN, FLT_MAX);


    return 0;
}
