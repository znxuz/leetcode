#include <stdio.h>
#include "function.h"

static void check(char *str1, char *str2)
{
	printf("str1: [%s], str2: [%s], isomorphic: [%s]\n", str1, str2,
			isIsomorphic(str1, str2) ? "true" : "false");
}

int main(void)
{
}
