#include <stdio.h>
#include <string.h>

#include "Lib.h"

char PROJECT_DIR[] = "D:/Allgemein/Udemy/C_Komplettkurs/UdemyC/";

int main()
{
    char input_filepath[100] = {'\0'};
    strcpy(input_filepath, PROJECT_DIR);
    strcat(input_filepath, "Chapter11_Files/FileModes/InputData.txt");

    char output_filepath[100] = {'\0'};
    strcpy(output_filepath, PROJECT_DIR);
    strcat(output_filepath, "Chapter11_Files/FileModes/OutputData.bin");

    FILE *fp_in = fopen(input_filepath, "r");

    if (fp_in == NULL)
        return 1;

    Vector *v1 = createVector(5, 0);

    for (unsigned int i = 0; i < v1->length; i++)
    {
        fscanf(fp_in, "%d", &v1->data[i]);
    }

    fclose(fp_in);

    printVector(v1);

    for (unsigned int i = 0; i < v1->length; i++)
    {
        v1->data[i] -= 1;
    }

    FILE *fp_out = fopen(output_filepath, "wb");

    if (fp_out == NULL)
        return 1;

    for (unsigned int i = 0; i < v1->length; i++)
    {
        fprintf(fp_out, "%d\n", v1->data[i]);
    }

    fclose(fp_out);

    v1 = freeVector(v1);

    return 0;
}
