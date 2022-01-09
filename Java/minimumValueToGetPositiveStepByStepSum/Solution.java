// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

package minimumValueToGetPositiveStepByStepSum;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int minStartValue(int[] nums) {
		int sum = 0;
		int btmSum = 0;
		for (int n : nums) {
			sum += n;
			btmSum = Math.min(btmSum, sum);
		}

		return btmSum < 1 ? Math.abs(btmSum) + 1 : btmSum;
    }
}
