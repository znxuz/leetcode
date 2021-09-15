// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include "function.h"

#define SUM(a, b) a + b

int *twoSum(int *nums, int nums_size, int target, int *return_size)
{
	*return_size = 2;
	int *ret = malloc(sizeof *ret * *return_size);
	int left_i = 0;
	int right_i = nums_size - 1;
	while (left_i < right_i) {
		if (SUM(*(nums + left_i), *(nums + right_i)) < target)
			left_i++;
		else if (SUM(*(nums + left_i), *(nums + right_i)) > target)
			right_i--;
		else
			break;
	}

	*ret = ++left_i;
	*(ret + 1) = ++right_i;
	return ret;
}
