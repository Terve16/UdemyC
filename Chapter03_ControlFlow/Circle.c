#define _USE_MATH_DEFINES // does not work -> M_PI is not available
#include <math.h>
#include <stdbool.h>
#include <stdio.h>


int main()
{

    double pi = acos(-1.0);
    printf("%lf\n", pi);

    double radius;
    double perimeter;
    double area;

    printf("Please enter the radius of the circle: ");
    scanf("%lf", &radius);

    if (radius > 0)
    {
        perimeter = (2 * radius * pi);
        area = (pow(radius, 2) * pi);

        printf("The perimeter of the circle is %lf and the area is %lf.\n", perimeter, area);
    }
    else
    {
        printf("The input %lf is invalid!", radius);
    }

    return 0;
}
