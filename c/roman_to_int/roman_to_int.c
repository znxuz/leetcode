// https://leetcode.com/problems/roman-to-integer/

#include <stdlib.h>
#include <string.h>

static int get_roman_val(char c)
{
	switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

static int check_substract(int first, int second)
{
	if ((first == 1 && (second == 5 || second == 10))
			|| (first == 10 && (second == 50 || second == 100))
			|| (first == 100 && (second == 500 || second == 1000)))
		return 1;
	return 0;
}

int romanToInt(char *str)
{
	int result = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		int first = get_roman_val(*(str + i));
		int second = i + 1 < len ?
			check_substract(first, get_roman_val(*(str + i + 1))) ?
			get_roman_val(*(str + ++i)) : 0 : 0;
		if (second)
			first = -first;
		result += first + second;
	}
	
	return result;
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", romanToInt("IV"));
	printf("%d\n", romanToInt("MCMXCIV"));
}
