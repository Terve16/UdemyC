#include <stdio.h>

int main()
{
    int number;

    printf("Please enter a valid unsigned integer! ");
    scanf("%d", &number);

    if ((number % 3) == 0)
    {
        printf("The number you entered is div. by 3!\n");
    }
    else
    {
        printf("The number you entered is not div. by 3!\n");
        printf("The remainder of the operation is: %d\n", (number % 3));
    }

    return 0;
}
