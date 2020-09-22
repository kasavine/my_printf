#include <stdio.h> //delete before submitting
int main()
{
	char c = 'C';
	char *string = "STRING with some words in it";

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
    my_printf("before [%c] after, and [%c], and [%c]", c, '4', '~');
    printf("\n");
    printf("before [%c] after, and [%c], and [%c]", c, '4', '~');
	printf("\n\n");
	
    // testing seq of chars
    my_printf("before [%s] after", string);
    printf("\n");
    printf("before [%s] after", string);
	printf("\n\n");

    // void * - printed in hexadecimal
    int a = 10;
    int *b = &a;
    printf("%x\n",b); //       45b6a334          d46c6714
    printf("%p\n",b); // 0x7ffe45b6a334    0x7ffcd46c6714

	return 0;
}