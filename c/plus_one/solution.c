#include <stdlib.h>

static int get_newsize(int *digits, int digits_size)
{
	int i;

	for (i = 0; i < digits_size; i++) {
		if (*(digits + i) != 9)
			return digits_size;
	}

	return i == digits_size ? digits_size + 1 : digits_size;
}

static void inc_from_last(int *digits, int last_index)
{
	*(digits + last_index) = *(digits + last_index) == 9 ?
		0 : *(digits + last_index) + 1;
	if (!*(digits + last_index))
		inc_from_last(digits, --last_index);
}

static void arr_copy(int *dest, int *src, int size)
{
	while (size--)
		*(dest + size) = *(src + size);
}

int* plusOne(int *digits, int digits_size, int *return_size)
{
	*return_size = get_newsize(digits, digits_size);

	int *return_digits = calloc(*return_size, sizeof *return_digits);
	arr_copy(return_digits + (*return_size - digits_size), digits, digits_size);
	inc_from_last(return_digits, *return_size - 1);

	return return_digits;
}

#include <stdio.h>

static void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	puts("");
}

int main(void)
{
	int size;
	int *arr = plusOne((int[]){9}, 1, &size);
	print_arr(arr, size);
	free(arr);
}
