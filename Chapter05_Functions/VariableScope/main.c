#include <stdio.h>

int a = 1;

void func()
{
    int b = 2;

    printf("FUNC a = %d\n", a);
    printf("FUNC b = %d\n", b);
}


int main()
{
    {
        int c = 3;
        printf("MAIN c = %d\n", c);
    }

    func();

    printf("MAIN a = %d\n", a);

    return 0;
}
