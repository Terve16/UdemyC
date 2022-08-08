#include <stdio.h>

int main()
{
    int age1 = 28;
    int age2 = 56;

    // 1. If Else
    int older_age1;
    if (age1 > age2)
        older_age1 = age1;
    else
        older_age1 = age2;

    // 2. Ternary Operator
    //               BOOL EXPR     ? True : False
    int older_age2 = (age1 > age2) ? age1 : age2;

    printf("%i, %i\n", older_age1, older_age2);

    return 0;
}
