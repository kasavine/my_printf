#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char* s)
{
    int i = 0;
    while (s[i])
    {
        my_putchar(s[i++]);
    }
}

int my_strlen(char* str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}
char* itoa_unsigned_base(unsigned int number, int base)
{
    unsigned int original_n = number;
    unsigned int len = 0;
    char* result;
    unsigned int temp_n;

    original_n = original_n > 0 ? original_n : -original_n;
    while (number)
    {
        number = number / base;
        len++;
    }
    if (!(result = (char*)malloc(sizeof(char) * len + 1)))
    {
        return (0);
    }
    *(result + len) = '\0';
    len--;
    while (original_n > 0)
    {
        temp_n = original_n % base;
        if (temp_n < 10)
            *(result + len) = temp_n + '0';
        else
            *(result + len) = ((temp_n)-10 + 97);
        original_n = original_n / base;
        len--;
    }
    if (len == 0 && result[1] == '\0')
    {
        *(result + len) =  0;
    }
    return result;
}

char* itoa_signed_base(int number, int base)
{
    int original_n = number;
    int len;
    char* result;
    int temp_n;

    len = original_n > 0 ? 0 : 1;
    original_n = original_n > 0 ? original_n : -original_n;
    while (number)
    {
        number = number / base;
        len++;
    }
    if (!(result = (char*)malloc(sizeof(char) * len + 1)))
    {
        return (0);
    }
    *(result + len) = '\0';
    len--;
    while (original_n > 0)
    {
        temp_n = original_n % base;
        if (base == 16 && original_n < 0)
        {
            temp_n = 15 - temp_n + 1;
        }
        if (temp_n < 10)
            *(result + len) = temp_n + '0';
        else
            *(result + len) = ((temp_n)-10 + 97);
        original_n = original_n / base;
        len--;
    }
    if (len == 0 && result[1] == '\0')
    {
        *(result + len) =  0;
    }
    else if (len == 0 && result[1] != '\0')
    {
        *(result + len) = '-';
    }
    return result;
}

char* pointer_to_string(unsigned long int number, int base)
{
    unsigned long int original_n = number;
    unsigned int len = 0;
    char* result;
    unsigned long int temp_n;

    original_n = original_n > 0 ? original_n : -(original_n);
    while (number)
    {
        number = number / base;
        len++;
    }
    if (!(result = (char*)malloc(sizeof(char) * len + 1)))
    {
        return (0);
    }
    *(result + len) = '\0';
    len--;
    while (original_n > 0)
    {
        temp_n = original_n % base;
        if (temp_n < 10)
            *(result + len) = temp_n + '0';
        else
            *(result + len) = ((temp_n)-10 + 97);
        original_n = original_n / base;
        len--;
    }
    return result;
}

int my_printf(char* restrict format, ...)
{
    va_list args_p;
    char* p;
    int len;
    int value;
    char* sval;
    char* res_convert = NULL;
    intptr_t value_p;
    int written_chars = 0;

    va_start(args_p, format);
    for (p = format; *p; p++)
    {
        if (*p != '%')
        {
            my_putchar(*p);
            written_chars++;
            continue;
        }
        switch (*++p)
        {
            case 'd':
            {
                value = va_arg(args_p, int);
                res_convert = itoa_signed_base(value, 10);
                my_putstr(res_convert);
                len = my_strlen(res_convert);
                written_chars += len;
                break;
            }
            case 'o':
            {
                value = va_arg(args_p, int);
                res_convert = itoa_unsigned_base(value, 8);
                my_putstr(res_convert);
                len = my_strlen(res_convert);
                written_chars += len;
                break;
            }
            case 'u':
            {
                value = va_arg(args_p, int);
                res_convert = itoa_unsigned_base(value, 10);
                my_putstr(res_convert);
                len = my_strlen(res_convert);
                written_chars += len;
                break;
            }
            case 'x':
            {
                value = va_arg(args_p, int);
                res_convert = itoa_unsigned_base(value, 16);
                my_putstr(res_convert);
                len = my_strlen(res_convert);
                written_chars += len;
                break;
            }
            case 'c':
            {
                value = va_arg(args_p, int);
                my_putchar(value);
                written_chars++;
                break;
            }
            case 's':
            {
                sval = va_arg(args_p, char*);
                my_putstr(sval);
                len = my_strlen(sval);
                written_chars += len;
                break;
            }
            case 'p':
            {
                value_p = va_arg(args_p, intptr_t);
                res_convert = pointer_to_string(value_p, 16);
                write(1, "0x", 2);
                my_putstr(res_convert);
                len = my_strlen(res_convert);
                written_chars += len + 2;
                break;
            }
        }
        if (res_convert != NULL)
        {
            free(res_convert);
            res_convert = NULL;
        }
    }
    return written_chars;
    va_end(args_p);
}
