// https://leetcode.com/problems/excel-sheet-column-number/

#include "function.h"

#define BASE 26
#define OFFSET 64

int title_to_num_rec(char *col_title, int *exponent)
{
	int result = 0;
	if (*(col_title + 1))
		result = title_to_num_rec(col_title + 1, exponent);
	result += (*col_title - OFFSET) * pow(BASE, (*exponent)++);

	return result;
}

int titleToNumber(char *column_title)
{
	return title_to_num_rec(column_title, (int[]){0});
}
