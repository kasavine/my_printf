# my_printf

```
int my_printf(char * restrict format, ...);
```
my_printf() function writes output to stdout, the standard output stream.

Function that works almost like real printf.

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; 
and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the % character. 
The arguments must correspond properly (after type promotion) with the conversion specifier. 
After the %, the following appear in sequence:

- **doux** The int argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
- **c** The int argument is converted to an unsigned char, and the resulting character is written.
- **s** The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
- **p** The void * pointer argument is printed in hexadecimal.

What to learn?
- variadic functions (can receive an unknown amount of arguments and you can cycle through them using a specific library)
- variable argument lists

**Declararion of the variadic function** - do it like you usually do and add three dots "..." as the last argument. 
It means that there is possibility of additional arguments, but it is not mandatory.

The printf is probably the most notable function that uses this principle. 
The printf will take N amount of arguments and has many different parameters to format the output it will print.

**<stdarg.h>**
- macro va_list: to initialize the arguments pointer
- macro va_start: to point to the first element (of the mandatory one(s)
- macro va_arg: to point to the first of the optional arguments the user entered and every time it is called it will move over to the next argument
- macro va_end: GCC will not even notice it but you could still add it in case you use a different compiler
- macro va_copy:

The list is declared by using the va_list macro, then the user checks if the list is empty or not. 
After this, the list is initiated using the va_start macro and passing the name of the list as well as the amount of arguments it has (represented by the letter ‘n’ in this case).

- print a character 
- print a set of characters - string (char *)
- print signed decimal
- print unsigned decimal
- print unsigned octal
- print unsigned hexadecimal
- print the address of pointer - hexadecimal with 0x....
- **-g3 -fsanitize=address** (test code against memory errors by compiling with the debugging flags)
- **-Wall -Wextra -Werror** (code must be compiled with the flags)
- *write, malloc, free, stdarg.h*


