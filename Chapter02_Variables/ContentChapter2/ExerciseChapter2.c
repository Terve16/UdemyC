#include <stdio.h>

int main()
{
    unsigned int age_years;

    printf("Please enter your age in full years: ");
    scanf("%u", &age_years);

    printf("You are living since %u days.\n", (age_years * 365));
    printf("You are living since %u hours.\n", (age_years * 365 * 24));
    printf("You are living since %u minutes.\n", (age_years * 365 * 24 * 60));
    printf("You are living since %u seconds.\n", (age_years * 365 * 24 * 60 * 60));

    return 0;
}
