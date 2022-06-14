#include <stdio.h>

int main()
{
    int my_value = 1337;

    // &: memory address
    printf("Value of my_value: %d\n", my_value);
    printf("Memory address of my_value: %p\n", &my_value);
    printf("Size of my_value: %lu\n", sizeof(my_value));

    int *my_pointer = &my_value;

    // &: memory address
    printf("Value of my_pointer: %p\n", my_pointer);
    printf("Memory address of my_pointer: %p\n", &my_pointer);
    printf("Size of my_pointer: %lu\n", sizeof(my_pointer));

    printf("Value of the reference of my_pointer: %d\n", *my_pointer);

    return 0;
}
