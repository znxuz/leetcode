#include <stdio.h>
#include "function.h"

static void check(int *nums, int nums_size)
{
	printf("max: %d\n", maxSubArray(nums, nums_size));
}

int main(void)
{
	int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	check(nums, sizeof nums / sizeof *nums);
}
