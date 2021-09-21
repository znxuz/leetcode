// https://leetcode.com/problems/contains-duplicate/

#include "solution.h"

void merge(int *nums, int left, int mid, int right)
{
	int sorted[right - left + 1];
	int index = 0;
	
	int l = left;
	int r = mid + 1;
	while (l <= mid && r <= right) {
		if (*(nums + l) <= *(nums + r))
			*(sorted + index++) = *(nums + l++);
		else
			*(sorted + index++) = *(nums + r++);
	}
	while (l <= mid)
		*(sorted + index++) = *(nums + l++);
	while (r <= right)
		*(sorted + index++) = *(nums + r++);
	index = 0;
	for (int i = left; i <= right; i++)
		*(nums + i) = *(sorted + index++);
}

void merge_sort(int *nums, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (left < right) {
		merge_sort(nums, left, mid);
		merge_sort(nums, mid + 1, right);
	}

	merge(nums, left, mid, right);
}

bool containsDuplicate(int *nums, int nums_size)
{
	merge_sort(nums, 0, nums_size - 1);
	for (int i = 0; i < nums_size - 1; i++) {
		if (*(nums + i) == *(nums + i + 1))
			return true;
	}

	return false;
}
