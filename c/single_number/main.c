#include <stdio.h>
#include "function.h"

int main(void)
{
	int arr[] = {1, 2, 2, 1, 5, 3, 5, 3, 7};
	printf("%d\n", singleNumber(arr, sizeof arr / sizeof *arr));
}
