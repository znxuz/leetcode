#include <stdio.h>
#include "function.h"

void check()
{
	int lower = -1, upper = 0;
	int arr[] = {-1};
	int arr_size = sizeof arr / sizeof *arr;
	int ranges_size;
	char **ranges =
		findMissingRanges(arr, arr_size, lower, upper, &ranges_size);
	for (int i = 0; i < ranges_size; i++)
		printf("%s\n", *(ranges + i));
	for (int i = 0; i < ranges_size; i++)
		free(*(ranges + i));
	free(ranges);
}

int main(void)
{
	check();
}
