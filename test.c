
#include <stdio.h> 
#include <assert.h>
#include <assert.h>
int my_printf(char *restrict format, ...);

int main()
{
    printf("\n");
    printf(" <<<<<<<<<< TEST FOR d: signed decimal >>>>>>>>>\n");
    int len_d = my_printf("MY PRINT: [%d], [%d], [%d]\n", 2048, -1337, 0);
    int len_d_o = printf("ORIGINAL: [%d], [%d], [%d]\n", 2048, -1337, 0);
    printf("my LEN is %d    \nLEN_O is %d\n", len_d, len_d_o);
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR o: unsigned octal >>>>>>>>> \n");
    int len_o = my_printf("MY PRINT: [%o], [%o], [%o], [%o]\n", 1000, -8, 8, 0);
    int len_o_o = printf("ORIGINAL: [%o], [%o], [%o], [%o]\n", 1000, -8, 8, 0);
    printf("my LEN is %d    \nLEN_O is %d\n", len_o, len_o_o);    
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR u: unsigned decimal >>>>>>>>> \n");
    int len_u = my_printf("MY PRINT: [%u], [%u], [%u]\n", 1337, 256, 0);
    int len_u_o = printf("ORIGINAL: [%u], [%u], [%u]\n", 1337, 256, 0);
    printf("my LEN is %d    \nLEN_O is %d\n", len_u, len_u_o);
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR x: unsigned hexadecimal >>>>>>>>> \n");
    int len_x = my_printf("MY PRINT: [%x], [%x], [%x], [%x], [%x]\n", 14, 16, 3405723, -3405723, 0);
    int len_x_o = printf("ORIGINAL: [%x], [%x], [%x], [%x], [%x]\n", 14, 16, 3405723, -3405723, 0);
    printf("my LEN is %d    \nLEN_O is %d\n", len_x, len_x_o);
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR c: unsigned char >>>>>>>>> \n");
    int len_c = my_printf("MY PRINT: [%c], [%c], [%c]\n", 'C', '4', '~');
    int len_c_o = printf("ORIGINAL: [%c], [%c], [%c]\n", 'C', '4', '~');
    printf("my LEN is %d    \nLEN_O is %d\n", len_c, len_c_o);
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR p: printed in hexadecimal >>>>>>>>> \n");
    int a = 10;
    int *b = &a;
    int len_p = my_printf("MY PRINT: [%p]\n", b);
    int len_p_o = printf("ORIGINAL: [%p]\n", b);
    printf("my LEN is %d    \nLEN_O is %d\n", len_p, len_p_o);
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR s: pointer to a string >>>>>>>>> \n");
    int len_s = my_printf("MY PRINT: [%s] [%s]\n", "STRING with some words in it", "and second argument");
    int len_s_o = printf("ORIGINAL: [%s] [%s]\n", "STRING with some words in it", "and second argument");
    printf("my LEN is %d    \nLEN_O is %d\n", len_s, len_s_o);
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR empty ss >>>>>>>>> \n");
    int len_ss = my_printf("MY PRINT: [%s]\n", "");
    int len_ss_o = printf("ORIGINAL: [%s]\n", "");
    printf("my LEN is %d    \nLEN_O is %d\n", len_ss, len_ss_o);
    printf("\n");

    printf(" <<<<<<<<<< TEST FOR NULL ss >>>>>>>>> \n");
    int len_sss = my_printf("MY PRINT: [%s]!\n", (char*)NULL);
    int len_sss_o = printf("ORIGINAL: [%s]!\n", (char*)NULL);
    printf("my LEN is %d    \nLEN_O is %d\n", len_sss, len_sss_o);
    printf("\n");

    // printf("LEN is %d, LEN_O is %d\n\n", my_printf("NULL STRING [%s]!\n", (char*)NULL), printf("NULL STRING [%s]!\n", (char*)NULL));
    // my_printf("NULL STRING [%s]!\n", (char*)NULL);
    // printf("NULL STRING [%s]!\n", (char *)NULL);
	return 0;
}