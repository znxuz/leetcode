// https://leetcode.com/problems/contains-duplicate-ii/

#include <stdbool.h>

// time limit exceeded
bool containsNearbyDuplicate(int *nums, int nums_size, int k)
{
	for (int i = 0; i < nums_size; i++) {
		for (int j = i + 1; j <= i + k && j < nums_size; j++) {
			if (*(nums + i) == *(nums + j))
				return true;
		}
	}
	return false;
}
