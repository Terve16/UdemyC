#include <math.h>
#include <stdio.h>

void my_function(int val)
{
    printf("%d\n", val);
}

int main()
{
    int i = 0;

    // Post-Increment
    // i++;
    // printf("%d\n", i);
    printf("%d\n", i++); // increment after printf

    // Pre-Increment
    // ++i;
    // printf("%d\n", i);
    printf("%d\n", ++i);

    int j = 0;

    // Post-Increment
    my_function(j++);

    // Pre-Increment
    my_function(++j);

    printf("\n\n");
    // no difference in for loop

    // Post-Increment
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", i);
    }

    // Pre-Increment
    for (int i = 0; i < 3; ++i)
    {
        printf("%d\n", i);
    }

    // conclusion: use pre-increment in most cases

    return 0;
}
