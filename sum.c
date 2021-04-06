
#include <stdarg.h>
#include <stdio.h>
int sum_example(const unsigned int n, ...){
	int i;
	int sum;
	va_list args;   // to get each argument
	va_start(args, n); // starting
	
	sum = 0;
	for (i = 0; i < n; i++){
		sum = sum + va_arg(args, int);  //every time - new
	}
	va_end(args); // ending
	return (sum);
}

int main(int argc, char const *argv[]){
	int i = sum_example(6, 2, 3, 5, 7, 0, 3);
	printf("sum = %d", i);
	return 0;
}