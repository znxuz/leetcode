#include "function.h"
#include <stdio.h>

unsigned long long factorial(int n)
{
	if (!n)
		return n;
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}

int main(void)
{
	for (int i = 0; i < 22; i++)
		printf("factorial of %d: %llu\n", i, factorial(i));
}
