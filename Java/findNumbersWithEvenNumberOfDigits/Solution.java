// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

package findNumbersWithEvenNumberOfDigits;

class Solution {

    public int findNumbers(int[] nums) {
		int res = 0;
		for (int n : nums) {
			int ctr = 0;
			while (n > 0) {
				n /= 10;
				ctr++;
			}

			if (ctr % 2 == 0)
				res++;
		}

		return res;
    }
}
