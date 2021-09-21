// https://leetcode.com/problems/single-number/

#include "function.h"
#include <stdio.h>

int singleNumber(int *nums, int nums_size)
{
	int num = 0;
	for (int i = 0; i < nums_size; i++) {
		printf("i: %d, num = %d, nums[i]: %d, ", i, num, *(nums + i));
		num ^= *(nums + i);
		printf("xor: %d\n", num);
	}
	return num;
}
