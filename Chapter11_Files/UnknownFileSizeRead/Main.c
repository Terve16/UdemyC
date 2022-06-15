#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lib.h"

char PROJECT_DIR[] = "D:/Allgemein/Udemy/C_Komplettkurs/UdemyC/";

int main()
{
    char input_filepath[100] = {'\0'};
    strcpy(input_filepath, PROJECT_DIR);
    strcat(input_filepath, "Chapter11_Files/UnknownFileSizeRead/InputData.txt");

    FILE *fp = fopen(input_filepath, "r");

    if (fp == NULL)
        return 1;

    int line_size = 100;
    char line[100] = {'\0'};

    while (fgets(line, line_size, fp) != NULL)
    {
        printf("%s", line);

        int value = atoi(line);
        // float valuef = atof(line);

        printf("%d\n\n", value);
    }

    fclose(fp);

    return 0;
}
