#include <stdio.h>
#include <stddef.h>
#define GREEN "\033[32m" 
#define RED "\033[31;1m"
#define NORMAL "\033[0m"

#define PRINTF_PARAM_0_1 "Hello world!\n"
void test_0_1() {
  printf("<#0 - 1>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_0_1);
  int printf_ret_value = printf(PRINTF_PARAM_0_1);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#0 - 1>\n");
}

#define PRINTF_PARAM_2_3 "%c!\n", 'H'
void test_2_3() {
  printf("<#2 - 3>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_2_3);
  int printf_ret_value = printf(PRINTF_PARAM_2_3);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#2 - 3>\n");
}

#define PRINTF_PARAM_4_5 "%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'
void test_4_5() {
  printf("<#4 - 5>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_4_5);
  int printf_ret_value = printf(PRINTF_PARAM_4_5);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#4 - 5>\n");
}

#define PRINTF_PARAM_6_7 "Hello %s!\n", "QWASAR.IO"
void test_6_7() {
  printf("<#6 - 7>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_6_7);
  int printf_ret_value = printf(PRINTF_PARAM_6_7);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#6 - 7>\n");
}

#define PRINTF_PARAM_8_9 "Hello %s %s!\n", "Mr", "Gaetan"
void test_8_9() {
  printf("<#8 - 9>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_8_9);
  int printf_ret_value = printf(PRINTF_PARAM_8_9);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#8 - 9>\n");
}

#define PRINTF_PARAM_10_11 "NULL STRING %s!\n", (char *)NULL
void test_10_11() {
  printf("<#10 - 11>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_10_11);
  int printf_ret_value = printf(PRINTF_PARAM_10_11);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#10 - 11>\n");
}

#define PRINTF_PARAM_12_13 "%d!\n", 1337
void test_12_13() {
  printf("<#12 - 13>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_12_13);
  int printf_ret_value = printf(PRINTF_PARAM_12_13);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#12 - 13>\n");
}

#define PRINTF_PARAM_14_15 "%d - %d - %d!\n", 2048, 0, -1337
void test_14_15() {
  printf("<#14 15>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_14_15);
  int printf_ret_value = printf(PRINTF_PARAM_14_15);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#15 16>\n");
}

#define PRINTF_PARAM_16_17 "%o!\n", 100
void test_16_17() {
  printf("<#16 - 17>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_16_17);
  int printf_ret_value = printf(PRINTF_PARAM_16_17);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#16 - 17>\n");
}

#define PRINTF_PARAM_18_19 "%u!\n", 1337
void test_18_19() {
  printf("<#18 - 19>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_18_19);
  int printf_ret_value = printf(PRINTF_PARAM_18_19);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#18 - 19>\n");
}

#define PRINTF_PARAM_20_21 "%x!\n", 14
void test_20_21() {
  printf("<#20 - 21>\n");
  int my_printf_ret_value = my_printf(PRINTF_PARAM_20_21);
  int printf_ret_value = printf(PRINTF_PARAM_20_21);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#20 - 21>\n");
}


#define PRINTF_PARAM_22_23 "%x!\n", 14
void test_22_23() {
  int a = 3;
  printf("<#22 - 23>\n");
  int my_printf_ret_value = my_printf("%p!\n", &a);
  int printf_ret_value = printf("%p!\n", &a);
  printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
  printf("</#22 - 23>\n");
}

int main(int ac, char **av) {
    test_0_1();
    test_2_3();
    test_4_5();
    test_6_7();
    test_8_9();
    test_10_11();
    test_12_13();
    test_14_15();
    test_16_17();
    test_18_19();
    test_20_21();
    test_22_23();
    return 0;
}
