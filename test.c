#include <stdio.h> //delete before submitting
int main()
{
	char c = 'C';
	char *string = "STRING with some words in it";

    // testing signed decimal
    int len_d;
    int len_d_o;
    len_d = my_printf("signed decimal: [%d], [%d]", 18, -18);
    printf("\n");
    printf("my_length %d\n", len_d);
    len_d_o = printf("signed decimal: [%d], [%d]", 18, -18);
    printf("\n");
    printf("or_length %d\n", len_d_o);
	printf("\n");

    // testing unsigned octal
    int len_o;
    int len_o_o;
    len_o = my_printf("unsigned octal: [%o], [%o]", 7, -8);
    printf("\n");
    printf("my_length %d\n", len_o);
    len_o_o = printf("unsigned octal: [%o], [%o]", 7, -8);
    printf("\n");
    printf("or_length %d\n", len_o_o);
	printf("\n");

    // testing unsigned decimal
    int len_u;
    int len_u_o;
    len_u = my_printf("unsigned decimal: [%u], [%u]", 255, -109);
    printf("\n");
    printf("my_length %d\n", len_u);
    len_u_o = printf("unsigned decimal: [%u], [%u]", 255, -109);
    printf("\n");
    printf("or_length %d\n", len_u_o);
	printf("\n");

    // testing unsigned hexadecimal
    int len_x;
    int len_x_o;
    len_x = my_printf("unsigned hexadecimal: [%x], [%x], [%x], [%x]", 15, 16, 3405723, -3405723);
    printf("\n");
    printf("my_length %d\n", len_x);
    len_x_o = printf("unsigned hexadecimal: [%x], [%x], [%x], [%x]", 15, 16, 3405723, -3405723);
    printf("\n");
    printf("or_length %d\n", len_x_o);
	printf("\n");

    // testing unsigned char
    int len_c;
    int len_c_o;
    len_c = my_printf("before [%c] after, and [%c], and [%c]", c, '4', '~');
    printf("\n");
    printf("my_length %d\n", len_c);
    len_c_o = printf("before [%c] after, and [%c], and [%c]", c, '4', '~');
    printf("\n");
    printf("or_length %d\n", len_c_o);
	printf("\n");
	
    // testing seq of chars
    int len_s;
    int len_s_o;
    len_s = my_printf("before [%s] after", string);
    printf("\n");
    printf("my_length %d\n", len_s);
    len_s_o = printf("before [%s] after", string);
    printf("\n");
    printf("or_length %d\n", len_s_o);
	printf("\n");

    // void * - printed in hexadecimal
    int len_p;
    int len_p_o;

    int a = 10;
    int *b = &a;

    len_p = my_printf("before [%p] after", b);
    printf("\n");
    printf("my_length %d\n", len_p);
    len_p_o = printf("before [%p] after", b);
    printf("\n");
    printf("or_length %d\n", len_p_o);
	printf("\n");

    // different
    int len;
    int len_or;

    len = my_printf("%d %o %u %x %c %s %p", -12, 9, -10, 19, 'A', "ABC", b);
    printf("\n");
    printf("my_length %d\n", len);
    len_or = printf("%d %o %u %x %c %s %p", -12, 9, -10, 19, 'A', "ABC", b);
    printf("\n");
    printf("or_length %d\n", len_or);
	printf("\n");

	return 0;
}