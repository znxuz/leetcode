#include <string.h>

int lengthOfLastWord_solution(char *s)
{
	int len = strlen(s), word_len = 0;
	while (len--) {
		if (*(s + len) == ' ' && word_len)
			break;
		if (*(s + len) != ' ')
			word_len++;
	}
	return word_len;
}
