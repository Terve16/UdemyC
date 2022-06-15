#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lib.h"

char PROJECT_DIR[] = "D:/Allgemein/Udemy/C_Komplettkurs/UdemyC/";

int main()
{
    char input_filepath[100] = {'\0'};
    strncpy(input_filepath, PROJECT_DIR, 100);
    strncat(input_filepath, "Chapter11_Files/ContentChapter11/InputData.txt", 60);

    FILE *fp_read = fopen(input_filepath, "r");

    if (fp_read == NULL)
        return 1;

    sMatrix *smatrix = createSMatrix(10, 100, '\0');

    if (smatrix == NULL)
    {
        fclose(fp_read);
        return 1;
    }

    unsigned int i = 0;
    while (fgets(smatrix->svector[i]->data, smatrix->svector[i]->length, fp_read) != NULL)
    {
        i++;
        if (i >= smatrix->size)
            break;
    }

    printSMatrix(smatrix);

    freeSMatrix(smatrix);

    fclose(fp_read);


    return 0;
}
