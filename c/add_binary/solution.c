#include <stdlib.h>
#include <string.h>

#define OFFSET '0'

char * addBinary(char *a, char *b)
{
	int a_len = strlen(a);
	int b_len = strlen(b);
	int sum_len = a_len > b_len ? a_len : b_len;
	char *sum = malloc(sum_len + 2);
	int carry = 0;

	sum[sum_len + 1] = '\0';
	while (a_len || b_len) {
		if (a_len)
			carry += a[--a_len] - OFFSET;
		if (b_len)
			carry += b[--b_len] - OFFSET;
		sum[sum_len--] = (carry & 1) + OFFSET;
		carry >>= 1;
	}
	sum[0] = carry + OFFSET;
	return sum + (carry ^ 1);
		// if there is one carry, then return original
		// if no carry, return the next pointer, which is valid
}
