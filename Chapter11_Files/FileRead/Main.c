#include <stdio.h>
#include <string.h>

#include "Lib.h"

char PROJECT_DIR[] = "D:/Allgemein/Udemy/C_Komplettkurs/UdemyC/";

int main()
{
    char input_filepath[100] = {'\0'};
    strcpy(input_filepath, PROJECT_DIR);
    strcat(input_filepath, "Chapter11_Files/FileRead/InputData.txt");

    FILE *fp = fopen(input_filepath, "r");

    if (fp == NULL)
        return 1;

    Vector *v1 = createVector(5, 0);

    for (unsigned int i = 0; i < v1->length; i++)
    {
        fscanf(fp, "%d", &v1->data[i]);
    }

    fclose(fp);

    printVector(v1);

    v1 = freeVector(v1);

    return 0;
}
