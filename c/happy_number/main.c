#include <stdio.h>
#include "function.h"

static void check_func()
{
	int n = 11;
	for (int i = 0; i < 50; i++) {
	// while (n != 1) {
		long long sum = get_sum_digit_squared(n);
		printf("num: %d\t sum of squares of digits: %lld\n", n, sum);
		n = sum;
	}
}

int main(void)
{
	check_func();
}
