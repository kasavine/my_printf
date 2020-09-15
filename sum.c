
#include <stdarg.h>

int sum_all(const unsigned int n, ...)
{
	unsigned int i, sum;
	va_list args;

	if (args == 0)
		return (0);
	
	va_start(args, n);

	sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = sum + va_arg(args, int);
	}

	va_end(args);
	return (sum);
}

int main(int argc, char const *argv[])
{
	int i = sum_all(1, 2, 3);
	printf("sum = %d", i);
	
	return 0;
}