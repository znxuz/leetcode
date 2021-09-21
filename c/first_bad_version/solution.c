#include <stdbool.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

int firstBadVersion(int n, int left, int right)
{
}

int firstBadVersion_iterative(int n)
{
	int left, mid, right;
	left = 1, right = n;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (!isBadVersion(mid))
			left = mid + 1;
		else
			right = mid;
	}

	return left;
}
