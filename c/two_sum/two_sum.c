#include <stdlib.h>

int *twoSum(int *nums, int num_size, int target, int *return_size)
{
	*return_size = 2;
	int *ret = (int*) malloc(sizeof *ret * *return_size);
	for (int i = 0; i < num_size; i++) {
		for (int j = i + 1; j < num_size; j++) {
			if (*(nums + i) + *(nums + j) == target) {
				*ret = i;
				*(ret + 1) = j;
				return ret;
			}
		}
	}
	return 0;
}

#include <stdio.h>
int main(void) {
	int nums[] = {2, 7, 11, 15};
	int num_size = sizeof(nums) / sizeof(*nums);
	int target = 26;
	int ret_size;
	int *ret;

	ret = twoSum(nums, num_size, target, &ret_size);
	printf("%d\t%d\n", *ret, *(ret + 1));
}
