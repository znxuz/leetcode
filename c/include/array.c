#include "array.h"

void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	puts("");
}
