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
    strcpy(friends[0], "Joseph von Reding");
    strcpy(friends[1], "Peter Lustig");
    strcpy(friends[2], "Hans Meier");


    for (unsigned int i = 0; i < number_friends; i++)
    {
        printf("%s\n", friends[i]);
    }

    friends = freeFriendbook(friends, number_friends);

    return 0;
}
