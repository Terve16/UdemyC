#include <stdio.h>

enum Drink
{
    COLA,
    ICETEA,
    WATER,
    COFFEE
};

int main()
{

    int selection;
    printf("Please enter a valid drink: ");
    scanf("%d", &selection);

    switch (selection)
    {
    case COLA:
    {
        printf("You choose a cola");
        break;
    }
    case ICETEA:
    {
        printf("You choose a icetea");
        break;
    }
    case WATER:
    {
        printf("You choose a water");
        break;
    }
    case COFFEE:
    {
        printf("You choose a coffee");
        break;
    }
    default:
    {
        break;
    }
    }

    return 0;
}
