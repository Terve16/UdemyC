#include <stdio.h>

#include <stdarg.h>

void my_printer(char *format, ...)
{
    if (format == NULL)
        return;

    va_list arg = NULL;
    va_start(arg, format);

    unsigned int i = 0;

    while (format[i] != '\n')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
            {
                putchar('%');
            }
            else if (format[i] == 'c')
            {
                putchar(((char)va_arg(arg, int)));
            }
            else if (format[i] == 'd')
            {
                printf("%d", (va_arg(arg, int)));
            }
            else if (format[i] == 'u')
            {
                printf("%u", (va_arg(arg, unsigned int)));
            }
            else if (format[i] == 'f')
            {
                printf("%f", ((float)va_arg(arg, double)));
            }
            else if (format[i] == 'l')
            {
                i++;
                if (format[i] == 'f')
                {
                    printf("%lf", (va_arg(arg, double)));
                }
            }
            else if (format[i] == 's')
            {
                // printf("%s", va_arg(arg, char *));

                char *value = va_arg(arg, char *);

                while (*value != '\0')
                {
                    putchar(*value);

                    value++;
                }
            }
            else
            {
                putchar(' ');
            }
        }
        else
        {
            putchar(format[i]);
        }

        i++;
    }

    va_end(arg);
}

int main()
{
    my_printer("%c, %d, %u, %f, %lf, %s\n", 'a', -12, 13, 1337.5f, -1337.3, "Joseph");

    return 0;
}
