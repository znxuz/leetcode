// https://leetcode.com/problems/sqrtx/

package sqrt;

class Solution {

	// Calculator method
	// Newton's method
	// Recursion and bitwise-shift

    public int mySqrt(int x) {
		if (x < 2)
			return x;

		int left = 2;
		int right = x / 2;

		int mid = 0;
		long squared = 0;
		while (left <= right) {
			mid = left + (right - left) / 2;
			squared = (long)mid * mid; // a necessity to cast to long
			if (squared == x)
				return mid;
			if (squared < x)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return right;
	}
}
