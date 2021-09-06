#include <stdio.h>
#include "function.h"

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
