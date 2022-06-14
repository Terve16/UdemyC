#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    int my_number1 = 42;
    bool my_bool1 = true;
    int32_t my_number2 = 1337;

    int16_t my_number3 = 4321;

    int8_t my_number4 = (int8_t)my_number1;

    uint8_t my_number5 = (uint8_t)my_number4;

    float my_number6 = 1.25f;
    double my_number7 = 1.25;

    int64_t my_number8 = 5;

    short my_number9 = 3;

    printf("%d", sizeof(my_number9));

    return 0;
}
