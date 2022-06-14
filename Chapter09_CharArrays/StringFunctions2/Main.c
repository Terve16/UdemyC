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

int main()
{
    unsigned int number_friends = 3;

    char **friends = createFriendBook(number_friends);

    // friends[0] = "Joseph von Reding"; // Do not do that
    strncpy(friends[0], "Joseph von Reding", 20);
    strncpy(friends[1], "Peter Lustig", 20);
    strncpy(friends[2], "Hans Meier", 20);

    strncat(friends[0], " Dr.", 5);

    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    unsigned int length0 = strnlen(friends[0], 20);
    unsigned int length1 = strnlen(friends[1], 20);
    unsigned int length2 = strnlen(friends[2], 20);

    printf("%u\n", length0);
    printf("%u\n", length1);
    printf("%u\n", length2);

    int compare0 = strncmp(friends[0], friends[1], 20);
    int compare1 = strncmp(friends[0], friends[2], 20);
    int compare2 = strncmp(friends[1], friends[2], 20);

    printf("%d\n", compare0);
    printf("%d\n", compare1);
    printf("%d\n", compare2);

    char *found_char0 = strchr(friends[0], 'e');
    char *found_char1 = strrchr(friends[0], 'e');

    if (found_char0 != NULL)
    {
        printf("%s\n", found_char0);
    }

    if (found_char0 != NULL)
    {
        printf("%s\n", found_char1);
    }

    char *found_substr = strstr(friends[1], "tig");

    if (found_substr != NULL)
    {
        printf("%s\n", found_substr);
    }

    char *token = strtok(friends[0], " ");

    if (token != NULL)
    {
        printf("%s\n", token);
    }

    friends = freeFriendbook(friends, number_friends);

    return 0;
}
