#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name1[] = {'J', 'o', 's', 'e', 'p', 'h', '\0'}; // add \0 !!
    char name2[7] = {'J', 'o', 's', 'e', 'p', 'h', '\0'};
    char name3[] = "Joseph"; // \0 is added automatically
    char name4[32] = {'\0'};
    char *name5 = (char *)malloc(32 * sizeof(char));

    name5[0] = 'J';
    name5[1] = 'o';
    name5[2] = 's';
    name5[3] = 'e';
    name5[4] = 'p';
    name5[5] = 'h';
    name5[6] = '\0';

    for (unsigned int i = 0; i < 6; i++)
    {
        printf("%c", name5[i]);
    }
    printf("\n");

    printf("%s\n", name1);
    printf("%s\n", name2);
    printf("%s\n", name3);
    printf("%s\n", name4);
    printf("%s\n", name5);

    free(name5);
    name5 = NULL;

    return 0;
}
