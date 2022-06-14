#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **createFriendBook(unsigned int number_friends)
{
    char **friends = (char **)malloc(number_friends * sizeof(char *));

    if (friends == NULL)
        return NULL;

    for (unsigned int i = 0; i < number_friends; i++)
    {
        friends[i] = (char *)malloc(20 * sizeof(char));
    }

    return friends;
}

char **freeFriendbook(char **friends, unsigned int no_friends)
{
    if (friends == NULL)
        return NULL;

    for (unsigned int i = 0; i < no_friends; i++)
    {
        if (friends[i] == NULL)
            continue;

        free(friends[i]);
    }
    free(friends);
    friends = NULL;
    return NULL;
}

size_t string_length(char *string, unsigned int no_of_chars)
{
    if (string == NULL || no_of_chars == 0)
        return 0;

    for (unsigned int i = 0; i < no_of_chars; i++)
    {
        if (string[i] == '\0')
            return i;
    }

    return no_of_chars;
}


int main()
{
    unsigned int number_friends = 3;

    char **friends = createFriendBook(number_friends);

    // friends[0] = "Joseph von Reding"; // Do not do that
    strncpy(friends[0], "Joseph von Reding", 20);
    strncpy(friends[1], "Peter Lustig", 20);
    strncpy(friends[2], "Hans Meier", 20);

    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    unsigned int length0 = string_length(friends[0], 20);
    unsigned int length1 = string_length(friends[1], 20);
    unsigned int length2 = string_length(friends[2], 20);

    printf("%u\n", length0);
    printf("%u\n", length1);
    printf("%u\n", length2);


    friends = freeFriendbook(friends, number_friends);

    return 0;
}
