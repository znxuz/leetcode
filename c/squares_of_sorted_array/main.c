#include <stdio.h>
#include "function.h"
#include "../include/array.h"

int main(void)
{
	int *arr[] = {(int[]){0, 1, 2, 3, 4, 5},
				(int[]){-2, -1, 0, 1, 2},
				(int[]){-4, -3, -2, -1, 0}, // FIXME
				(int[]){-5, -4, -3, -2, -1},
				(int[]){1, 2, 3, 4, 5}};

	int single[] = {1};

	int row = sizeof arr / sizeof *arr;

	for (int i = 0; i < row; i++) {
		int squared_size;
		int *squared = sortedSquares(*(arr + i), 5, &squared_size);
		print_arr(squared, squared_size);
		free(squared);
	}

	int size;
	int *squared = sortedSquares(single, 1, &size);
	print_arr(squared, size);
	free(squared);
}
