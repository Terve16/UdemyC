#include <stdio.h>

int main()
{

    double M[2][3] = {{1, 0, 2}, {0, 1, 2}};

    int matrix_size = sizeof(M);
    printf("%u\n", matrix_size);

    int num_coumns = sizeof(M[0]) / sizeof(M[0][0]);
    printf("%u\n", num_coumns);

    int num_rows = sizeof(M) / sizeof(M[0]);
    printf("%u\n", num_rows);

    return 0;
}
