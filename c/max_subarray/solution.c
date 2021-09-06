#include <limits.h>

static int max(int x, int y)
{
	return x > y ? x : y;
}

int max_crossarray(int *nums, int left, int right, int mid)
{
	int sum, left_sum, right_sum;
	sum = left_sum = right_sum = 0;

	for (int i = left; i <= mid; i++) {
		sum += *(nums + i);
		if (sum > left_sum)
			left_sum = sum;
	}
	sum = 0;
	for (int i = mid + 1; i <= right; i++) {
		sum += *(nums + i);
		if (sum > right_sum)
			right_sum = sum;
	}

	return max(max(left_sum, right_sum), left_sum + right_sum);
}

int max_subarray(int *nums, int left, int right)
{
	if (left == right)
		return *(nums + left);

	int mid = (left + right) / 2;
	return max(max(max_subarray(nums, left, mid), max_subarray(nums, mid + 1, right)),
			max_crossarray(nums, left, right, mid));
}

int maxSubArray_solution(int* nums, int nums_size)
{
	return max_subarray(nums, 0, nums_size - 1);
}
