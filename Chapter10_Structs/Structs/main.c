#include <stdio.h>

struct Friend
{
    char name[50];
    char prename[50];
    unsigned int year;
    unsigned int month;
    unsigned int day;
};


int main()
{
    struct Friend joseph = {.name = "von Reding", .prename = "Joseph", .year = 1991U, .month = 1U, .day = 6U};
    struct Friend peter = {.name = "Lustig", .prename = "Peter", .year = 1959U, .month = 8U, .day = 13U};
    struct Friend hans = {.name = "Meier", .prename = "Hans", .year = 1970U, .month = 12U, .day = 31U};

    printf("%s\n", joseph.name);
    printf("%s\n", joseph.prename);
    printf("%d\n", joseph.year);

    printf("%s\n", peter.name);
    printf("%s\n", peter.prename);
    printf("%d\n", peter.year);

    printf("%s\n", hans.name);
    printf("%s\n", hans.prename);
    printf("%d\n", hans.year);

    return 0;
}
