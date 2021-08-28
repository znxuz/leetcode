// https://leetcode.com/problems/search-insert-position/

static int bi_search_index(int *nums, int begin, int end, int target)
{
	if (end - begin <= 1) {
		if (*(nums + begin) == target)
			return begin;
		if (*(nums + end) == target)
			return end;
		return target > *(nums + begin)
			? target < *(nums + end) ? end : end + 1
			: begin - 1 < 0 ? 0 : begin - 1;
	}

	int mid = (begin + end) / 2;
	if (*(nums + mid) < target)
		return bi_search_index(nums, mid, end, target);
	if (*(nums + mid) > target)
		return bi_search_index(nums, begin, mid, target);
	else
		return mid;
}

int searchInsert(int* nums, int nums_size, int target)
{
	return bi_search_index(nums, 0, nums_size - 1, target);
}

#include <stdio.h>

static void check(int *arr, int arr_size, int target)
{
	printf("index: %d\n", searchInsert(arr, arr_size, target));
}

int main(void)
{
			//   0, 1, 2, 3, 4
	int ar1[] = {1, 2, 3, 4, 5};
			//   0, 1, 2, 3, 4, 5
	int ar2[] = {1, 2, 4, 5, 6, 7};
	int target = 8;
	
	check(ar2, sizeof ar2 / sizeof *ar2, target);
}
