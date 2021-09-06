#include "function.h"
#include <stdio.h>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	printf("index: %d\n", search(arr, sizeof arr / sizeof *arr, 4));
}
