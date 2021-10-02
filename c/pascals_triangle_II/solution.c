// https://leetcode.com/problems/pascals-triangle-ii/

#include "solution.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int row_index, int *return_size)
{
	*return_size = row_index + 1;
	int *row = calloc(row_index + 1, sizeof *row);
	for (int i = 0; i <= row_index; i++) {
		int prev = *row = 1;
		for (int j = 1; j <= i; j++) {
			int tmp = *(row + j);
			*(row + j) = prev + *(row + j);
			prev = tmp;
		}
	}

	return row;
}
