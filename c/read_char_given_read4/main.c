#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "function.h"

int fd;

void check(void)
{
	static char *buffer;
	if (!buffer) {
		buffer = malloc(sizeof *buffer);
		printf("malloc\n");
	} else {
		free(buffer);
		buffer = NULL;
	}
}

int main(void)
{
	fd = open("./read_char_given_read4/testfile", O_RDONLY);
	char *buf = calloc(1000, sizeof *buf);
	_read(buf, 4);
	printf("%s\n", buf);
}
