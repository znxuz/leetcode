// https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/

package sumOfDigitsInTheMinNumber;

class Solution {

    public int sumOfDigits(int[] nums) {
		int min = nums[0];
		for (int i : nums) {
			if (min > i)
				min = i;
		}

		return (digitSum(min) & 1) == 0 ? 1 : 0;
    }

	public int digitSum(int n) {
		if (n < 10)
			return n;
		return n % 10 + digitSum(n / 10);
	}
}
