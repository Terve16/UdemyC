#include <stdio.h>

int main()
{
    int age_joseph = 31;
    int age_marc = 28;

    if (age_joseph < age_marc)
    {
        printf("Joseph is younger than Marc!");
    }
    else if (age_marc < age_joseph)
    {
        printf("Marc is younger than Joseph!");
    }
    else
    {
        printf("Joseph and Marc have the same age!");
    }

    return 0;
}
