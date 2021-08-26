#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

#include <stdio.h>
int main(void)
{
	printf("%d\n", isValid("(())"));
	printf("%d\n", isValid("[{}]()"));
}
