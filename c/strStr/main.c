// https://leetcode.com/problems/implement-strstr/

#include <string.h>

static int get_index_limit(char *haystack, char *needle)
{
	if (haystack && needle)
		return strlen(haystack) - strlen(needle);
	return 0;
}

int strStr(char * haystack, char * needle)
{
	if (!*haystack && !*needle)
		return 0;

	int index = 0;
	int limit = get_index_limit(haystack, needle);
	while (*(haystack + index) && index <= limit) {
		int j = 0;
		while (*(haystack + index + j) && *(needle + j)
				&& *(haystack + index + j) == *(needle + j))
			j++;
		if (!*(needle + j))
			return index;
		index++;
	}

	return -1;
}

#include <stdio.h>
int main(void)
{
	printf("index: %d\n", strStr("hello", "ell"));
	printf("index: %d\n", strStr("abc", "c"));
}
