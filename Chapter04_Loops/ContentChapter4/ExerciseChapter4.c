#include <stdio.h>

int main()
{
    printf("<\t^\t^\t^\t^\t>\n");

    for (int i = 1; i < (4 + 1); i++)
    {
        printf("<     ");
        for (int j = 1; j < (4 + 1); j++)
        {
            printf("(%d,%d)   ", i, j);
        }
        printf("  >\n");
    }

    printf("<\tv\tv\tv\tv\t>\n");

    return 0;
}
