#include <stdio.h>

#define NUM_STUDENTS 10


int main()
{
    const int grade_jan = 1;
    printf("%D\n", grade_jan);
    // grade_jan = 2; does not work

    int students_grades[NUM_STUDENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    return 0;
}
