#include "../include/array.h"

void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++) {
		if (!i)
			printf("[");
		printf("%d", *(arr + i));
		printf(i == size - 1 ? "]" : ", ");
	}
	puts("");
}
