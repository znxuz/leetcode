#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "function.h"

static void check(int num)
{
	char *title = convertToTitle(num);
	puts("result:");
	printf("col num: %d\ttitle: %s\n", num, title);
	free(title);
}

int main(void)
{
	for (int i = 0; i < 704; ++i) {
		check(i);
	}
}
