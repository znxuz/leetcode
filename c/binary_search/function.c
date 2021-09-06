// https://leetcode.com/problems/binary-search/

#include "function.h"

int search_rec(int *nums, int left, int right, int target)
{
	if (left == right)
		return target == *(nums + left) ? left : -1;
	
	int mid = (left + right) / 2;
	if (target < *(nums + mid))
		return search_rec(nums, left, mid, target);
	if (target > *(nums + mid))
		return search_rec(nums, mid + 1, right, target);
	return mid;
}

int search(int* nums, int nums_size, int target)
{
	int left, right, mid;
	left = 0, right = nums_size - 1;

	do {
		mid = (left + right) / 2;
		if (target < *(nums + mid))
			right = mid;
		if (target > *(nums + mid))
			left = mid + 1;
		if (target == *(nums + mid))
			return mid;
	} while (left < right);
	
	if (target == *(nums + left))
		return left;
	return -1;
}
