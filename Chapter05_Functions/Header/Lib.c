
#include "Lib.h"
#include <stdio.h>


// Definition
int getNumberFromUser()
{
    int number_from_user;

    printf("Please enter an integer number: ");
    scanf("%d", &number_from_user);

    return number_from_user;
}
