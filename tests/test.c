
#include <stdio.h> 
#include <assert.h>
#include <assert.h>
int my_printf(char *restrict format, ...);

int main()
{
    printf("-------test for d-------\n");
    int len_d = my_printf("my: [%d], [%d], [%d]\n", 2048, -1337, 0);
    int len_d_o = printf("nm: [%d], [%d], [%d]\n", 2048, -1337, 0);
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_d, len_d_o);

    printf("-------test for o-------\n");
    int len_o = my_printf("my: [%o], [%o], [%o], [%o]\n", 1000, -8, 8, 0);
    int len_o_o = printf("nm: [%o], [%o], [%o], [%o]\n", 1000, -8, 8, 0);
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_o, len_o_o);

    printf("-------test for u-------\n");
    int len_u = my_printf("my: [%u], [%u], [%u]\n", 1337, 256, 0);
    int len_u_o = printf("nm: [%u], [%u], [%u]\n", 1337, 256, 0);
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_u, len_u_o);

    printf("-------test for x-------\n");
    int len_x = my_printf("my: [%x], [%x], [%x], [%x], [%x]\n", 14, 16, 3405723, -3405723, 0);
    int len_x_o = printf("nm: [%x], [%x], [%x], [%x], [%x]\n", 14, 16, 3405723, -3405723, 0);
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_x, len_x_o);

    printf("-------test for c-------\n");
    int len_c = my_printf("my: [%c], [%c], [%c]\n", 'C', '4', '~');
    int len_c_o = printf("nm: [%c], [%c], [%c]\n", 'C', '4', '~');
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_c, len_c_o);

    printf("-------test for p,  printed in hexadecimal-------\n");
    int a = 10;
    int *b = &a;
    int len_p = my_printf("my: [%p]\n", b);
    int len_p_o = printf("nm: [%p]\n", b);
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_p, len_p_o);

    printf("-------test for s-------\n");
    int len_s = my_printf("my: [%s] [%s]\n", "STRING with some words in it", "and second argument");
    int len_s_o = printf("nm: [%s] [%s]\n", "STRING with some words in it", "and second argument");
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_s, len_s_o);

    printf("-------test for empty ss-------\n");
    int len_ss = my_printf("my: [%s]\n", "");
    int len_ss_o = printf("nm: [%s]\n", "");
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_ss, len_ss_o);

    printf("-------test NULL ss-------\n");
    int len_sss = my_printf("my: [%s]!\n", (char*)NULL);
    int len_sss_o = printf("nm: [%s]!\n", (char*)NULL);
    printf("my LEN is %d    \nLEN_O is %d\n\n", len_sss, len_sss_o);

    // printf("LEN is %d, LEN_O is %d\n\n", my_printf("NULL STRING [%s]!\n", (char*)NULL), printf("NULL STRING [%s]!\n", (char*)NULL));
    // my_printf("NULL STRING [%s]!\n", (char*)NULL);
    // printf("NULL STRING [%s]!\n", (char *)NULL);
	return 0;
}