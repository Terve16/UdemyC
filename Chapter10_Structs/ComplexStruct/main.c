#include <stdio.h>

typedef enum FriendshipOrigin
{
    FRIENDSHIP_ORIGIN_SCHOOL,
    FRIENDSHIP_ORIGIN_FAMILY,
    FRIENDSHIP_ORIGIN_OTHER,
} FriendshipOrigin_t;

typedef struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
} Date_t;


typedef struct Friend
{
    char name[50];
    char prename[50];
    Date_t date_of_birth;
    FriendshipOrigin_t origin;
} Friend_t;

// typedef struct Friend Friend_t;

void print_date(Date_t *date)
{
    printf("%u.%u.%u\n", date->day, date->month, date->year);
}

void print_friend(struct Friend *friend)
{
    printf("%s %s\n", friend->prename, friend->name);
    print_date(&friend->date_of_birth);
    printf("I know him from ");
    switch (friend->origin)
    {
    case FRIENDSHIP_ORIGIN_SCHOOL:
        printf("school");
        break;
    case FRIENDSHIP_ORIGIN_FAMILY:
        printf("family");
        break;
    case FRIENDSHIP_ORIGIN_OTHER:
        printf("somewhere else");
        break;

    default:
        printf("?");
        break;
    }
    printf(".\n");


    printf("\n");
}

int main()
{
    Friend_t joseph = {.name = "von Reding", .prename = "Joseph", .date_of_birth ={.year = 1991U, .month = 1U, .day = 6U}, .origin = FRIENDSHIP_ORIGIN_FAMILY};
    Friend_t peter = {.name = "Lustig", .prename = "Peter", .date_of_birth ={.year = 1959U, .month = 8U, .day = 13U}, .origin = FRIENDSHIP_ORIGIN_OTHER};
    struct Friend hans = {.name = "Meier", .prename = "Hans", .date_of_birth.year = 1970U, .date_of_birth.month = 12U, .date_of_birth.day = 31U, .origin = FRIENDSHIP_ORIGIN_SCHOOL};

    Friend_t *friend_book[] = {&joseph, &peter, &hans};

    print_friend(friend_book[0]);
    print_friend(friend_book[1]);
    print_friend(friend_book[2]);

    return 0;
}
