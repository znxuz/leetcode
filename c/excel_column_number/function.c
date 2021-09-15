// https://leetcode.com/problems/excel-sheet-column-title/

#include "function.h"

#define BASE 26
#define EXPONENT_OFFSET 1
#define NULL_CHAR_LEN 1

static int get_max_exponent(long base, int num)
{
	int max_expo = 0;
	while (base < num) {
		max_expo++;
		base = base + base * BASE;
	}

	return max_expo;
}

// unexpectedly hard
char *convertToTitle(int col_num)
{
	int max_expo = get_max_exponent(BASE, col_num);
	char *title = malloc(sizeof *title * max_expo + EXPONENT_OFFSET + NULL_CHAR_LEN);
	int index = 0;
	while (max_expo >= 0) {
		int times = col_num / pow(BASE, max_expo);
		if (col_num % (int)pow(BASE, max_expo) == 0
				&& (col_num > 26))
			times--;
		*(title + index++) = times + 64;
		col_num -= times * pow(BASE, max_expo);
		max_expo--;
	}
	*(title + index) = '\0';

	return title;
}
