
#include <stdarg.h>                      
#include <unistd.h>
#include <stdio.h> //delete before submitting

void my_putchar(char c)
{
    write(1, &c, 1);
}

void print_signed_decimal(va_list args_p);

void print_unsigned_octal(va_list args_p); 

void print_unsigned_decimal(va_list args_p); 

void print_unsigned_hexadecimal(va_list args_p);

void print_char(va_list args_p)
{
	int cval;
	cval = va_arg(args_p, int);
	my_putchar(cval);
}

void print_string(va_list args_p)
{
	char *sval;
	for (sval = va_arg(args_p, char *); *sval; sval++)
	{
		my_putchar(*sval);
	}
}

void my_printf(char *restrict format, ...)
{
    va_list args_p;
    char *p;
    char *sval;
	int ival;

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
			case 'd':  //dtoa
				ival = va_arg(args_p, int);
				printf("%d", ival);
				break;
			// o  // otoa
			// u   // utoa
			// x    // xtoa

			case 'c':
				print_char(args_p);
				break;
			case 's':
				print_string(args_p);
				break;
			// p
			default:
				my_putchar(*p);
				break;
        }
    }
    va_end(args_p); 
}

int main(int argc, char const *argv[])
{
	char c = 'C';
	char *string = "STRING";

	my_printf("before[ %c ]after", c);
	my_printf("\n");
	
	my_printf("before[ %s ]after", string);
	my_printf("\n");

	my_printf("before[ %s ]after, before[ %c ]after", string, c);
	my_printf("\n");
	
	// my_printf("\n");

    // my_printf("%s", "******");
	// my_printf("\n");

	// char *s = "abc";
	// int res = printf("%s\n", s);
	// printf("%d", res);

	return 0;
}
