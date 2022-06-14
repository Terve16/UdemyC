#include <stdint.h>
#include <stdio.h>


uint64_t factorial(uint8_t n)
{
    if (n == 1)
    {
        return 1;
    }

    return ((uint64_t)n) * factorial(n - 1);
}


int main()
{
    uint8_t n = 50;
    uint64_t n_faculty = factorial(n);

    printf("%u! = %lu\n", n, n_faculty);

    return 0;
}
