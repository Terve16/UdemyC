#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join(char *delimiter, char **list)
{
    if (delimiter == NULL ||
        list == NULL ||
        list[0] == NULL)
        return NULL;

    unsigned int no_of_elem = 1;
    unsigned int no_of_char = strlen(list[0]);

    while (list[no_of_elem] != NULL)
    {
        no_of_char += strlen(list[no_of_elem]);
        no_of_elem ++;
    }

    unsigned int result_str_char_no = (1 + no_of_char + ((no_of_elem -1) * strlen(delimiter)));

    char *string = (char *)calloc(result_str_char_no, sizeof(char));

    if (string == NULL)
        return NULL;

    strcpy(string, list[0]);  // init of string

    for (unsigned int i = 1; i < no_of_elem; i++)
    {
        strcat(string, delimiter);
        strcat(string, list[i]);
    }

    return string;
}

int main()
{
    char *list1[] = {NULL};
    char *list2[] = {"Clara", NULL};
    char *list3[] = {"Clara", "Florian", NULL};
    char *list4[] = {"Clara", "Florian", "Jan", NULL};
    char *s = NULL;

    s = join(" -> ", list1); // ""
    if (s != NULL)
    {
        printf("List1: %s\n", s);
        free(s);
    }

    s = join(" -> ", list2); // "Clara"
    if (s != NULL)
    {
        printf("List2: %s\n", s);
        free(s);
    }

    s = join(" -> ", list3); // "Clara -> Florian"
    if (s != NULL)
    {
        printf("List3: %s\n", s);
        free(s);
    }

    s = join(" -> ", list4); // "Clara -> Florian -> Jan"
    if (s != NULL)
    {
        printf("List4: %s\n", s);
        free(s);
    }

    return 0;
}
