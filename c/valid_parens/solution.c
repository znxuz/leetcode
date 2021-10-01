#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool isValid(char *s)
{
	int len = strlen(s);
	char *stack = malloc(len);
	int top = -1;

	while (*s) {
		if (*s == '(' || *s == '[' || *s == '{') {
			*(stack + ++top) = *s;
		} else {
			if (top == -1)
				return false;
			if (*s == ')' && *(stack + top--) != '(')
				return false;
			if (*s == ']' && *(stack + top--) != '[')
				return false;
			if (*s == '}' && *(stack + top--) != '{')
				return false;
		}
		s++;
	}

	free(stack);
	if (top != -1)
		return false;
	return true;
}

int main(int argc, char **argv)
{
	printf("%s\n", isValid(*(argv + 1)) ? "true" : "false");
}
