// https://leetcode.com/problems/squares-of-a-sorted-array/

#include "function.h"

static int find_sorted_mid(int *nums, int nums_size)
{
	for (int i = 0; i < nums_size - 1; i++) {
		if (!*(nums + i) || (*(nums + i) < 0 && *(nums + i + 1) > 0))
			return i;
	}
	return *(nums + nums_size - 1) > 0 ? 0 : nums_size - 1;
}

static int square(int x)
{
	return x * x;
}

// O(n)
int *sortedSquares(int *nums, int nums_size, int *return_size)
{
	*return_size = nums_size;
	int *ret = malloc(sizeof(int) * *return_size);
	int left = find_sorted_mid(nums, nums_size);
	int right = left + 1; // left and right must not be the same value !
	int ret_i = 0;

	while (left >= 0 && right < nums_size)
		*(ret + ret_i++) = abs(*(nums + left)) <= *(nums + right) ?
			square(*(nums + left--)) : square(*(nums + right++));
	while (left >= 0)
		*(ret + ret_i++) = square(*(nums + left--));
	while (right < nums_size)
		*(ret + ret_i++) = square(*(nums + right++));

	return ret;
}
