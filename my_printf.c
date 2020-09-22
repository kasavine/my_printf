#include <stdarg.h>                      
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *s)
{
    int i = 0;
    while(s[i])
    {
        my_putchar(s[i]);
        i++;
    }
}

// char *itoa_base(int number, int base, int sign) // va_list args_p
// {
//     long value = number;
//     if (sign == 1) {
//         value = (unsigned int) number;
//     }
//     // TODO
//     return (NULL);
// }


char *itoa_unsigned_base(unsigned int number, int base)
{
    unsigned int original_n;
    unsigned int len;
    char *result;
    unsigned int temp_n;

    original_n = number;
    len = 0;
    original_n = original_n > 0 ? original_n : -original_n;
    while (number)
    {
        number = number / base;
        len++;
    }
    result = (char *)malloc(sizeof(char) * len + 1);
    if (!(result))
        return (0);
    *(result + len) = '\0';
    len--;
    while(original_n > 0)
    {
        temp_n = original_n % base;
        if (temp_n < 10) {
            *(result + len) = temp_n + '0';
        } else {
            *(result + len) = ((temp_n) - 10 + 97);
        }
        original_n = original_n / base;
        len--;
    }
    return (result);
}

char *itoa_signed(int number, int base) // va_list args_p
{
    int original_n;
    int len;
    char *result;
    int temp_n;

    original_n = number;
    len = original_n > 0 ? 0 : 1;
    original_n = original_n > 0 ? original_n : -original_n;
    while (number)
    {
        number = number / base;
        len++;
    }
    result = (char *)malloc(sizeof(char) * len + 1);
    if (!(result))
        return (0);
    *(result + len) = '\0';
    len--;
    while(original_n > 0)
    {
        temp_n = original_n % base;
        if (base == 16 && original_n < 0) { // n, originalNumber
            temp_n = 15 - temp_n + 1;
        }
        if (temp_n < 10) {
            *(result + len) = temp_n + '0';
        } else {
            *(result + len) = ((temp_n) - 10 + 97); // 97 A, 65 a
        }
        original_n = original_n / base;
        len--;
    }
    if (len == 0 && result[1] != '\0')
        *(result + len) = '-';
    return (result);
}

void my_printf(char *restrict format, ...)
{
    va_list args_p;
    char *p;
    int value;
    char *sval;
    char *res_convert;

    va_start(args_p, format);
    
    for (p = format; *p; p++)
    {
        if (*p != '%')
        {
            my_putchar(*p);
            continue;
        }
        switch (*++p)
        {
			case 'd':
                value = va_arg(args_p, int);
                res_convert = itoa_signed(value, 10);
                my_putstr(res_convert);
				break;
            case 'o':
                value = va_arg(args_p, int);
                res_convert = itoa_unsigned_base(value, 8);
                my_putstr(res_convert);
                break;
            case 'u':
                value = va_arg(args_p, int);
                res_convert = itoa_unsigned_base(value, 10);
                my_putstr(res_convert);
                break;
			case 'x':
                value = va_arg(args_p, int);
                res_convert = itoa_unsigned_base(value, 16);
                my_putstr(res_convert);
                break;
			case 'c':
                value = va_arg(args_p, int);
                my_putchar(value);       
				break;
			case 's':
                sval = va_arg(args_p, char *);
                my_putstr(sval);
				break;
            case 'p':
			    // p // print a pointer???
                break;
			default:
				my_putchar(*p);
				break;
        }
    }
    va_end(args_p); 
}