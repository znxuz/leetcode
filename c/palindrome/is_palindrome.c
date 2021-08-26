// https://leetcode.com/problems/palindrome-number/

#include <stdbool.h>
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

bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	if (x != reverse(x))
		return false;
	return true;
}

#include <stdio.h>
static void check(int x)
{
	printf("number: %d\t", x);
	printf("%s\n", isPalindrome(x) == 1 ? "true" : "false");
}

int main(void)
{
	check(1234321);
	check(100001);
	check(101101);
	check(1000021);
}
