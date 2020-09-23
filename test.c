
#include <stdio.h> //delete before submitting
int my_printf(char *restrict format, ...);

int main()
{
	char *string = "STRING with some words in it";

    // testing signed decimal
    int len_d = my_printf("[%d], [%d], [%d]\n", 18, -18, 0);
    int len_d_o = printf("[%d], [%d], [%d]\n", 18, -18, 0);
    printf("LEN is %d\nLEN_O is %d\n\n", len_d, len_d_o);

    // testing unsigned octal
    int len_o = my_printf("[%o], [%o]\n", 7, -8);
    int len_o_o = printf("[%o], [%o]\n", 7, -8);
    printf("LEN is %d\nLEN_O is %d\n\n", len_o, len_o_o);

    // testing unsigned decimal
    int len_u = my_printf("[%u], [%u], [%u]\n", 255, 1, 0);
    int len_u_o = printf("[%u], [%u], [%u]\n", 255, 1, 0);
    printf("LEN is %d\nLEN_O is %d\n\n", len_u, len_u_o);

    // testing unsigned hexadecimal
    int len_x = my_printf("[%x], [%x], [%x], [%x]\n", 15, 16, 3405723, -3405723);
    int len_x_o = printf("[%x], [%x], [%x], [%x]\n", 15, 16, 3405723, -3405723);
    printf("LEN is %d\nLEN_O is %d\n\n", len_x, len_x_o);

    // testing unsigned char
    int len_c = my_printf("[%c], [%c], [%c]\n", 'C', '4', '~');
    int len_c_o = printf("[%c], [%c], [%c]\n", 'C', '4', '~');
    printf("LEN is %d\nLEN_O is %d\n\n", len_c, len_c_o);

    // testing seq of chars
    int len_s = my_printf("[%s]\n", string);
    int len_s_o = printf("[%s]\n", string);
    printf("LEN is %d\nLEN_O is %d\n\n", len_s, len_s_o);

    // void * - printed in hexadecimal
    int a = 10;
    int *b = &a;
    int len_p = my_printf("[%p]\n", b);
    int len_p_o = printf("[%p]\n", b);
    printf("LEN is %d\nLEN_O is %d\n\n", len_p, len_p_o);

    printf("LEN is %d, LEN_O is %d\n\n", my_printf("Hello %s %s!\n", "Mr", "Gaetan"), printf("Hello %s %s!\n", "Mr", "Gaetan"));
    printf("LEN is %d, LEN_O is %d\n\n", my_printf("%d!\n", 1337), printf("%d!\n", 1337));
    printf("LEN is %d, LEN_O is %d\n\n", my_printf("%d - %d - %d!\n", 2048, 0, -1337), printf("%d - %d - %d!\n", 2048, 0, -1337));
    printf("LEN is %d, LEN_O is %d\n\n", my_printf("%o!\n", 100), printf("%o!\n", 100));
    printf("LEN is %d, LEN_O is %d\n\n", my_printf("%u!\n", 1337), printf("%u!\n", 1337));
    printf("LEN is %d, LEN_O is %d\n\n", my_printf("%x!\n", 14), printf("%x!\n", 14));
    printf("LEN is %d, LEN_O is %d\n\n", my_printf("%p!\n", b), printf("%p!\n", b));
    // printf("LEN is %d, LEN_O is %d\n\n", my_printf("NULL STRING [%s]!\n", (char*)NULL), printf("NULL STRING [%s]!\n", (char*)NULL));

	return 0;
}