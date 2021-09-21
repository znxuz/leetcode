// https://leetcode.com/problems/add-binary/

#include <stdlib.h>
#include <string.h>

char * addBinary(char *a, char *b)
{
	// solution
	return NULL;
}

#include <stdio.h>

int main(void)
{
	char *a = "10";
	char *b = "1";
	char *res = addBinary(a, b);
	printf("%s + %s = %s\n", a, b, res);
	free(res);
}
