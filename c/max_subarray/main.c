// https://leetcode.com/problems/maximum-subarray/

static int max(int x, int y)
{
	return x > y ? x : y;
}

int maxSubArray(int* nums, int nums_size)
{
	int max_sum = nums_size == 0 ? 0 : *nums;
	
	for (int i = 0; i < nums_size; i++) {
		int j = i;
		int sum = 0;
		do {
			sum += *(nums + j);
			max_sum = max(max_sum, sum);
		} while (++j < nums_size);
	}

	return max_sum;
}

#include <stdio.h>

static void check(int *nums, int nums_size)
{
	printf("max: %d\n", maxSubArray(nums, nums_size));
}

int main(void)
{
	int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	check(nums, sizeof nums / sizeof *nums);
}
