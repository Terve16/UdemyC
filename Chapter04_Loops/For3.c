#include <stdint.h>
#include <stdio.h>

int main()
{
    int32_t height;

    printf("Print Triangle\nPlease insert height of triangle: ");
    scanf("%d", &height);

    if (height <= 0)
    {
        printf("Invalid input");
        return 0;
    }

    for (int32_t i = 0; i < height; i++)
    {
        for (int32_t j = 0; j <= i; j++)
        {
            printf("1");
        }
        printf("\n");
    }

    for (int32_t i = (height - 1); i >= 0; i--)
    {
        for (int32_t j = 0; j <= i; j++)
        {
            printf("1");
        }
        printf("\n");
    }

    return 0;
}
