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

// char *xtoa(int number, int base, int sign) // va_list args_p
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
    unsigned int n;
    unsigned int len;
    char *result;
    unsigned int tempNumber;
    unsigned int originalNumber;

    originalNumber = number;
    n = number;
    len = 0;
    n = n > 0 ? n : -n;
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
    while(n > 0)
    {
        tempNumber = n % base;
        if (tempNumber < 10) {
            *(result + len) = tempNumber + '0';
        } else {
            *(result + len) = ((tempNumber) - 10 + 97);
        }
        n = n / base;
        len--;
    }
    return (result);
}

char *itoa_signed(int number, int base) // va_list args_p
{
    int n;
    int len;
    char *result;
    int tempNumber;
    int originalNumber;

    originalNumber = number;
    n = number;
    len = n > 0 ? 0 : 1;
    n = n > 0 ? n : -n;
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
    while(n > 0)
    {
        tempNumber = n % base;
        if (base == 16 && originalNumber < 0) {
            tempNumber = 15 - tempNumber + 1;
        }
        if (tempNumber < 10) {
            *(result + len) = tempNumber + '0';
        } else {
            *(result + len) = ((tempNumber) - 10 + 97); // 97 A, 65 a
        }
        n = n/base;
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

#include <stdio.h> //delete before submitting
int main()
{
	char c = 'C';
	char *string = "STRING";

    // testing signed decimal
    my_printf("signed decimal: result of my_printf [%d], [%d]", 18, -18);
    printf("\n");
    printf("signed decimal: original result [%d], [%d]", 18, -18);
	printf("\n\n");

    // testing unsigned octal
    my_printf("unsigned octal: result of my_printf [%o], [%o]", 7, -8);
    printf("\n");
    printf("unsigned octal: original result [%o], [%o]", 7, -8);
	printf("\n\n");

    // testing unsigned decimal
    my_printf("unsigned decimal: result of my_printf [%u], [%u]", 255, -109);
    printf("\n");
    printf("unsigned decimal: original result [%u], [%u]", 255, -109);
	printf("\n\n");

    // testing unsigned hexadecimal
    my_printf("unsigned hexadecimal: result of my_printf [%x], [%x], [%x], [%x]", 15, 16, 3405723, -3405723);
    printf("\n");
    printf("unsigned hexadecimal: original result [%x], [%x], [%x], [%x]", 15, 16, 3405723, -3405723);
	printf("\n\n");

    // testing unsigned char
    my_printf("before[ %c ]after", c);
    printf("\n");
    printf("before[ %c ]after", c);
	printf("\n\n");
	
    // testing seq of chars
    my_printf("before[ %s ]after", string);
    printf("\n");
    printf("before[ %s ]after", string);
	printf("\n\n");

    // void * - printed in hexadecimal
    int a = 10;
    int *b = &a;
    printf("%x\n",b); //       45b6a334          d46c6714
    printf("%p\n",b); // 0x7ffe45b6a334    0x7ffcd46c6714

	return 0;
}