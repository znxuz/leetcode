// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

package convertIntegerToTheSumOfTwoNonZeroIntegers;

class Solution {

    public int[] getNoZeroIntegers(int n) {
		for (int i = 1; i < n; ++i) {
			int diff = n - i;
			if (!containsZero(i) && !containsZero(diff))
				return new int[]{diff, i};
		}

		return new int[]{};
    }

	public boolean containsZero(int n) {
		while (n > 0) {
			if (n % 10 == 0)
				return true;
			n /= 10;
		}

		return false;
	}
}
