// https://leetcode.com/problems/remove-element/

int removeElement(int* nums, int nums_size, int val)
{
	for (int i = 0; i < nums_size; i++) {
		if (*(nums + i) == val) {
			for (int j = i; j < nums_size - 1; j++) {
				*(nums + j) = *(nums + j + 1);
			}
			nums_size--;
			i--;
		}
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

int main(void) {
	int arr[] = {1, 2, 3, 4, 4, 5, 6};
	int size = sizeof arr / sizeof *arr;
	print_arr(arr, size);
	size = removeElement(arr, size, 4);
	print_arr(arr, size);
}
