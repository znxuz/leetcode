// https://leetcode.com/problems/reverse-bits/

#include "function.h"

// solution
uint32_t reverseBits(uint32_t n)
{
	int power = 31;
	uint32_t ret = 0;
	while (n > 0) {
		ret += (n & 1) << power;
		n = n >> 1;
		power--;
	}

	return ret;
}
