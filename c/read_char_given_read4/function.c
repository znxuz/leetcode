// https://leetcode.com/problems/read-n-characters-given-read4/

#include "function.h"

extern int fd;

int read4(char *buf4)
{
	return read(fd, buf4, 4);
}

#define BUF_LEN 4

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(char *buf, int n)
{
	static int s_buf_index;
	static int s_buf_len;
	static char *s_buf;
	int buf_ctr = 0;

	if (!s_buf) {
		s_buf = malloc(sizeof *s_buf * BUF_LEN);
		s_buf_index = 0;
		s_buf_len = 0;
	} else {
		// copy left-over buf to destination
		while (s_buf_index < s_buf_len && n--)
			*(buf + buf_ctr++) = *(s_buf + s_buf_index++);
	}

	while (n) {
		if (s_buf_index == s_buf_len) {
			s_buf_index = 0;
			s_buf_len = read4(s_buf);
			if (!s_buf_len)
				break;
		}
		while (s_buf_index < s_buf_len && n) {
			*(buf + buf_ctr++) = *(s_buf + s_buf_index++);
			n--;
		}
	}

	return buf_ctr;
}
