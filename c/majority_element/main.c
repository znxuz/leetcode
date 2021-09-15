#include <stdio.h>
#include "function.h"
#include "../include/array.h"

int main(void)
{
	int arr[] = {5, 3, 7, 2, 9, 6};
	int size = sizeof arr / sizeof *arr;
	print_arr(arr, size);
	merge_sort(arr, 0, size - 1);
	print_arr(arr, size);
}
