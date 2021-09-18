// https://leetcode.com/problems/happy-number/

#include "function.h"

long long get_sum_digit_squared(int n)
{
	long long sum = 0;
	while (n) {
		sum += pow(n % 10, 2);
		n /= 10;
	}

	return sum;
}

// floyd's cycle finding
bool isHappy(int n)
{
	long long slow, fast;
	slow = fast = n;
	do {
		slow = get_sum_digit_squared(slow);
		fast = get_sum_digit_squared(get_sum_digit_squared(fast));
	} while (slow != fast);
	
	return slow == 1;
}
