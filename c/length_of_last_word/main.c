// https://leetcode.com/problems/length-of-last-word/

#include <string.h>

int lengthOfLastWord(char *s)
{
	if (!s || !*s)
		return 0;

	char *ptr = s + strlen(s) - 1;
	int len = 0;
	while (ptr > s && *ptr == ' ')
		ptr--;
	while (ptr + len >= s && *(ptr + len) != ' ')
		len--;

	return -len;
}
