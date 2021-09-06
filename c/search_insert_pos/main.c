#include <stdio.h>
#include "function.h"

static void check(int *arr, int arr_size, int target)
{
	printf("index: %d\n", searchInsert(arr, arr_size, target));
}

int main(void)
{
			//   0, 1, 2, 3, 4
	int ar1[] = {1, 2, 3, 4, 5};
			//   0, 1, 2, 3, 4, 5
	int ar2[] = {1, 2, 4, 5, 6, 7};
	int target = 8;
	
	check(ar2, sizeof ar2 / sizeof *ar2, target);
}
