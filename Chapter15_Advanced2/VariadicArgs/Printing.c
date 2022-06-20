#include <stdio.h>

#include <stdarg.h>
#include <string.h>

void my_printer(char *format, ...)
{
    if (format == NULL)
        return;

    unsigned int length = (unsigned int)strlen(format);

    unsigned int va_length = 0;

    for (unsigned int i = 0; i < length; i++)
    {
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            va_length++;
        }
    }

    if (va_length == 0)
    {
        printf(format);
        return;
    }

    va_list arg = NULL;
    va_start(arg, format);

    for (unsigned int i = 0; i < length; i++)
    {
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            putchar(((char)va_arg(arg, int)));
            i++;
        }
        else
        {
            putchar(format[i]);
        }
    }

    va_end(arg);
    printf("\n");
}

int main()
{
    my_printer("%c ---- %c\n", 'a', 'b'); // "a --- b"

    return 0;
}
