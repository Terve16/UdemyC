#include <stdbool.h>
#include <stdio.h>

int main()
{
    int num_iterations = 5;
    int i = 0;
    int goal = 13;
    int selection;

    printf("Welcome to our guessing game!\n");
    printf("You have to guess the right number from the interval of [1, 20].\n");


    do
    {
        printf("Please enter a number:\n");
        scanf("%d", &selection);

        if (selection == goal)
        {
            printf("You won the game!\n");
            break;
        }
        else if ((selection < 1) || (selection > 20))
        {
            printf("The number %d is not inside the interval of [1, 20].\n", selection);
        }
        else
        {
            printf("The number %d is wrong.\n", selection);
        }

        i++;

        if (i < num_iterations)
        {
            printf("You have %d trials left.\n\n", (num_iterations - i));
        }
        else
        {
            printf("You have lost the game!\n");
        }

    } while (i < num_iterations);


    return 0;
}
