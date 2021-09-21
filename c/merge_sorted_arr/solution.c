// https://leetcode.com/problems/merge-sorted-array/

#include "function.h"

static void shift_right(int *nums, int count, int shift)
{
	for (int i = 0; i < count; i++)
		*(nums + count - 1 + shift + i) = *(nums + count - 1 + i);
}

static void copy_over(int *dest, int *src, int size)
{
	for (int i = 0; i < size; i++)
		*(dest + i) = *(src + i);
}

void merge_alternative(int *nums1, int nums1_size, int m, int *nums2, int nums2_size, int n)
{
	int merged_size = nums1_size;
	int *merged = malloc(sizeof *merged * merged_size);
	m--;
	n--;
	while (m >= 0 || n >= 0) {
		if (m < 0)
			*(merged + --merged_size) = *(nums2 + n--);
		else if (n < 0)
			*(merged + --merged_size) = *(nums1 + m--);
		else
			*(merged + --merged_size) = *(nums1 + m) > *(nums2 + n) ? *(nums1 + m--) : *(nums2 + n--);
	}
	copy_over(nums1, merged, nums1_size);
	free(merged);
}

void merge(int *nums1, int nums1_size, int m, int *nums2, int nums2_size, int n)
{
	int i = m - 1, j = n - 1, tar = m + n - 1;
	while (j >= 0)
		*(nums1 + tar--) = i >= 0 && *(nums1 + i) > *(nums2 + j) ?
			*(nums1 + i--) : *(nums2 + j--);
}
