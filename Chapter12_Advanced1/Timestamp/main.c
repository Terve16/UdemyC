#include <stdio.h>
#include <time.h>

void do_something()
{
    volatile double value = 0.0; // volatile -> force compiler to keep something

    for (int i = 0; i < 1000000000; i++)
    {
        value *= i;
    }
}

int main()
{
    time_t time_start = time(NULL);

    // .....
    do_something();

    time_t time_end = time(NULL);

    double s = ((double)difftime(time_end, time_start)); // resolution only seconds
    double ms = 1000.0 * s; // s * 10^3
    double mus = 1000.0 * ms; // s * 10^6
    double ns = 1000.0 * mus; // s * 10^9

    printf("Size of clock_t: %lu\n", sizeof(clock_t));
    printf("Size of double: %lu\n", sizeof(double));
    printf("\n");

    printf("Seconds: %lf\n", s);
    printf("Milliseconds: %lf\n", ms);
    printf("Microseconds: %lf\n", mus);
    printf("Nanoseconds: %lf\n", ns);


    printf("Timestamp: %d\n", (int)time_end);
    printf("Time Format: %s\n", ctime(&time_end));

    return 0;
}
