// https://leetcode.com/problems/missing-ranges/

#include "function.h"

#define NULL_CHAR_LEN 1

int get_num_len(int num)
{
	if (num < 0)
		return 1 + get_num_len(-num);
	if (num < 10)
		return 1;
	return 1 + get_num_len(num / 10);
}

static int get_range_size(int lower, int upper)
{
	if (lower == upper)
		return get_num_len(lower);
	return 2 + get_num_len(lower) + get_num_len(upper);
}

char *itoa(int num)
{
	int num_len = get_num_len(num);
	char *num_str = malloc(sizeof *num_str * num_len + NULL_CHAR_LEN);
	*(num_str + num_len--) = '\0';

	if (!num)
		*num_str = '0';
	if (num < 0) {
		*num_str = '-';
		num = -num;
	}
	while (num) {
		*(num_str + num_len--) = num % 10 + '0';
		num /= 10;
	}

	return num_str;
}

char *get_range(int lower, int upper)
{
	int range_size = get_range_size(lower, upper);
	char *range = malloc(sizeof *range * range_size + NULL_CHAR_LEN);
	*(range + range_size) = '\0';

	char *lower_str = itoa(lower);
	char *upper_str = itoa(upper);

	memmove(range, lower_str, strlen(lower_str));
	if (lower != upper) {
		memmove(range + strlen(lower_str), "->", 2);
		memmove(range + strlen(lower_str) + 2, upper_str, strlen(upper_str));
	}
	free(lower_str);
	free(upper_str);

	return range;
}

char **findMissingRanges(int *nums, int nums_size, int lower, int upper, int *return_size)
{
	*return_size = !nums_size ? 1 : 0;
	if (nums_size && *nums > lower)
		(*return_size)++;
	for (int i = 0; i < nums_size - 1; i++) {
		if (*(nums + i + 1) - *(nums + i) != 1)
			(*return_size)++;
	}
	if (nums_size && *(nums + nums_size - 1) < upper)
		(*return_size)++;

	char **ranges_arr = malloc(sizeof *ranges_arr * *return_size);
	if (nums_size) {
		int arr_index = 0;
		if (*nums > lower)
			*(ranges_arr + arr_index++) = get_range(lower, *nums - 1);
		for (int i = 0; i < nums_size - 1; i++) {
			if (*(nums + i + 1) - *(nums + i) > 1)
				*(ranges_arr + arr_index++) = get_range(*(nums + i) + 1, *(nums + i + 1) - 1);
		}
		if (*(nums + nums_size - 1) < upper)
			*(ranges_arr + arr_index++) = get_range(*(nums + nums_size - 1) + 1, upper);
	} else {
		*ranges_arr = get_range(lower, upper);
	}

	return ranges_arr;
}
