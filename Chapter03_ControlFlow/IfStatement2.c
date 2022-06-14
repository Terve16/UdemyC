#include <stdio.h>

int main()
{
    int age_joseph = 31;
    int age_marc = 28;
    int age_sarah = 30;

    // &&: Conjunction, logical AND operator
    // ||: Disjunction, logical OR operator
    // !: Negation, logical NOT operator

    if ((age_joseph < age_marc) && (age_joseph < age_sarah))
    {
        printf("Joseph is the youngest!");
    }
    else if ((age_marc < age_joseph) && (age_marc < age_sarah))
    {
        printf("Marc is the youngest!");
    }
    else if ((age_sarah < age_joseph) && (age_sarah < age_marc))
    {
        printf("Sarah is the youngest!");
    }

    return 0;
}
