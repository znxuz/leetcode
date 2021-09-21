#include "function.h"

int majorityElement_solution(int *nums, int nums_size)
{
	// Boyer-Moore Majority Vote Algorithm
	int majority;
	int count = 0;
	for (int i = 0; i < nums_size; i++) {
		if (!count) {
			majority = *(nums + i);
			count++;
		} else if (majority != *(nums + i)) {
			count--;
		} else {
			count++;
		}
	}
	return majority;
}
