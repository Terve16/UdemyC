#include <stdbool.h>
#include <stdio.h>

int main()
{
    printf("Welcome to the square calculator.\n");

    double a;

    while (true)
    {
        printf("Please enter the lenght a of the square:\n");
        scanf("%lf", &a);

        if (a > 0)
        {
            printf("The perimeter of the square is %lf and the area is %lf.\n", (a + a), (a * a));
            break;
        }
        else
        {
            printf("The length %lf is invalid!\nTry again.\n\n", a);
        }
    }

    return 0;
}
