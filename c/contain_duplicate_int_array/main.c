#include <stdio.h>
#include "solution.h"
#include "../include/array.h"

int main(void)
{
	int arr[] = {5, 2, 1, 83, 3, 5,3 , 7, 7};
	int arr_size = sizeof arr / sizeof *arr;

	print_arr(arr, arr_size);
	merge_sort(arr, 0, arr_size - 1);
	print_arr(arr, arr_size);
}
