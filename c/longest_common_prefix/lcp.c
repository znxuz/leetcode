// https://leetcode.com/problems/longest-common-prefix/

#include <stdlib.h>

int get_prefix_len(char **arr, int arr_size)
{
	int index = 0;
	while (*(*arr + index)) {
		for (int i = 1; i < arr_size; i++) {
			if (*(*arr + index) != *(*(arr + i) + index)) // be careful with ptrs
				return index;
		}
		index++;
	}
	return index;
}

char *longestCommonPrefix(char **arr, int arr_size)
{
	int prefix_len = get_prefix_len(arr, arr_size);

	char *prefix = malloc(prefix_len + 1);
	for (int i = 0; i < prefix_len; i++)
		*(prefix + i) = *(*arr + i);
	*(prefix + prefix_len) = '\0';

	return prefix;
}

#include <stdio.h>
int main(void)
{
	char *arr[] = {"floh", "flow", "flight"};
	char *ret = longestCommonPrefix(arr, sizeof(arr) / sizeof(*arr));
	printf("prefix: %s\n", ret);
	free(ret);
}
