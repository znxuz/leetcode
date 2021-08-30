// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

static void shift(int *dest, int *src, int count)
{
	for (int i = 0; i < count; i++)
		*(dest + i) = *(src + i);
}

int removeDuplicates(int* nums, int nums_size)
{
	// FIXME no spaghetti pls
	for (int i = 0; i < nums_size; i++) {
		int shift_size = 0;
		while (i + shift_size + 1 < nums_size && *(nums + i) == *(nums + shift_size + i + 1))
			shift_size++;
		if (shift_size)
			shift(nums + i + 1, nums + i + 1 + shift_size, nums_size - i - 1 - shift_size);
		nums_size -= shift_size;
	}

	return nums_size;
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
	int arr[] = {1, 1, 1, 1, 1, 1 ,2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof arr / sizeof *arr;
	
	print_arr(arr, size);
	size = removeDuplicates(arr, size);
	print_arr(arr, size);
}
