// https://leetcode.com/problems/valid-perfect-square/

package validPerfectSquare;

class Solution {

	// 1 2 3 4 5 6 7 8 9 10 ...
    public boolean isPerfectSquare(int num) {
		if (num < 2)
			return true;

		int left = 2;
		int right = num / 2;
		int mid = -1;
		long squared = -1;
		while (left <= right) {
			mid = left + (right - left) / 2;
			squared = (long)mid * mid; // cast needed, or long mid
			if (squared == num)
				return true;
			if (squared > num)
				right = mid - 1;
			else
				left = mid + 1;
		}

		return false;
    }
}
