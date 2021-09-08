// https://leetcode.com/problems/pascals-triangle/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include "function.h"

// !! DO NOT USE STATIC FUNCTION WHEN TRYNA MALLOC !!
int **get_arr(int rows, int **return_col_size)
{
	int **arr = malloc(sizeof *arr * rows);
	*return_col_size = malloc(sizeof **arr * rows);
	while (rows-- > 0) {
		*(arr + rows) = malloc(sizeof **arr * rows);
		*(*return_col_size + rows) = rows + 1;
	}

	return arr;
}

int **generate(int rows, int *return_size, int **return_col_size)
{
	int **arr = get_arr(rows, return_col_size);
	*return_size = rows;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0 || j == i)
				*(*(arr + i) + j) = 1;
			else
				*(*(arr + i) + j) = *(*(arr + i - 1) + j - 1) + *(*(arr + i - 1) + j);
		}
	}

	return arr;
}
