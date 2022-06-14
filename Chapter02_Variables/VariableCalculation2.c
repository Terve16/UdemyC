#include <stdio.h>

int main()
{
    float a = 5.0f;
    float b = 2.0f;
    float c = 1.0f;

    // Addition
    //c = c + a;
    c += a;
    printf("c = c + a = %f\n", c);

    // Subtraction
    //c = c - a;
    c -= a;
    printf("c = c - a = %f\n", c);

    // Multiplication
    //c = c * a;
    c *= a;
    printf("c = c * a = %f\n", c);

    // Division
    //c = c / a;
    c /= a;
    printf("c = c / a = %f\n", c);

    b = b + 1;
    printf("b = b + 1 = %f\n", b);

    b += 1;
    printf("b = b + 1 = %f\n", b);

    b++;
    printf("b = b + 1 = %f\n", b);

    return 0;
}
