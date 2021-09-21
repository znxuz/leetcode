// https://leetcode.com/problems/reverse-integer/

#include <limits.h>

int reverse(int x)
{
	long result = 0;

	while (x != 0) {
		result = result * 10 + x % 10;
		if (result < INT_MIN || result > INT_MAX)
			return 0;
		x /= 10;
	}
	
	return result;
}

#include <stdio.h>
#include <math.h>
int main(void)
{
	printf("%d\n", reverse(1234));
	printf("%d\n", reverse(-1234));
	printf("%d\n", reverse(-12345));
	printf("%d\n", reverse(2147483647));
	printf("%d\n", reverse(1234567899));
}
