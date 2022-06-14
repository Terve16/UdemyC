#include <stdio.h>

int main()
{

    // Calculate the area of a rectangle

    double a;
    double b;

    printf("Please enter the length a of the rectangle: \n");
    scanf("%lf", &a);
    printf("Now please enter the length b of the rectangle: \n");
    scanf("%lf", &b);

    printf("The area of the rectangle is: %lf. The perimeter is: %lf.\n", (a * b), (2 * a + 2 * b));

    return 0;
}
