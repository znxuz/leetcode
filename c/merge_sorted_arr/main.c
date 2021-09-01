// https://leetcode.com/problems/merge-sorted-array/

#include <stdlib.h>

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

#include <stdio.h>

static void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	puts("");
}

int main(void)
{
	int arr1[] = {1, 3, 4, 7, 9, 10, 0, 0, 0, 0, 0}, arr1_size = sizeof arr1 / sizeof *arr1;
	int m = 6;
	int arr2[] = {1, 2, 3, 5, 8}, arr2_size = sizeof arr2 / sizeof *arr2;

	print_arr(arr1, arr1_size);
	print_arr(arr2, arr2_size);
	merge(arr1, arr1_size, m, arr2, arr2_size, arr2_size);
	print_arr(arr1, arr1_size);
}
