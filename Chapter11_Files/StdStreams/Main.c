#include <stdio.h>
#include <string.h>


char PROJECT_DIR[] = "D:/Allgemein/Udemy/C_Komplettkurs/UdemyC/";

int main()
{
    int data[5] = {0};

    for (unsigned int i = 0; i < 5; i++)
    {
        fscanf(stdin, "%d", &data[i]);
    }

    printf("\n");

    for (unsigned int i = 0; i < 5; i++)
    {
        fprintf(stdout, "STDOUT: %d\n", data[i]);
    }

    printf("\n");

    for (unsigned int i = 0; i < 5; i++)
    {
        fprintf(stderr, "STDERR: %d\n", data[i]);
    }

    return 0;
}
