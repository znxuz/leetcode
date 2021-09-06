// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/617/week-5-august-29th-august-31st/3958/

static int max(int x, int y)
{
	return x < y ? y : x;
}

static int min(int x, int y)
{
	return x < y ? x : y;
}

static int find_min_rec(int *nums, int l, int r)
{
	if (r - l <= 1)
		return min(*(nums + l), *(nums + r));

	int m = (l + r) / 2;
	if (*(nums + l) == max(max(*(nums + l), *(nums + m)), *(nums + r))
			|| *(nums + l) == min(min(*(nums + l), *(nums + m)), *(nums + r)))
		return find_min_rec(nums, l, m);
	return find_min_rec(nums, m + 1, r);
}

int findMin(int *nums, int nums_size)
{
	return find_min_rec(nums, 0, nums_size - 1);
}

#include <stdio.h>

int main(void)
{
			//i: 0  1  2  3  4  5  6
	int arr[] = {3, 4, 5, 1, 2};
	printf("%d\n", findMin(arr, sizeof arr / sizeof *arr));
}

// n = 7
// 0 1 2 3 4 5 6 -> l < m && l < r -> min in l +
// 6 0 1 2 3 4 5 -> l > m && l > r -> min in l +
// 5 6 0 1 2 3 4 -> l > m && l > r -> min in l +
// 4 5 6 0 1 2 3 -> l > m && l > r -> min in l +
// 3 4 5 6 0 1 2 -> l < m && l > r -> min in r -
// 2 3 4 5 6 0 1 -> l < m && l > r -> min in r -
// 1 2 3 4 5 6 0 -> l < m && l > r -> min in r -
// 0 1 2 3 4 5 6 -> l < m && l < r -> min in l +
