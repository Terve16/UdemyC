#include <stdbool.h>
#include <stdio.h>

int main()
{
    int num_iterations = 3;
    int i;

    while (true)
    {
        printf("Hello World!\n");

        i++;

        if (i >= num_iterations)
        {
            break;
        }
    }


    return 0;
}
