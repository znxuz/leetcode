// https://leetcode.com/problems/number-of-1-bits/

#include <stdint.h>

int hammingWeight(uint32_t n)
{
	int count = 0;
	while (n > 0) {
		count += n & 1;
		n >>= 1;
	}

	return count;
}
