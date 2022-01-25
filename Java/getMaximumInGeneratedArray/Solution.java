// https://leetcode.com/problems/get-maximum-in-generated-array/

package getMaximumInGeneratedArray;

class Solution {

	// time compleixty: O(n)
	// space compleixty: O(n)
    public int getMaximumGenerated(int n) {
		int[] dp = new int[n + 1];
		int max = 0;
		for (int i = 0; i < dp.length; ++i) {
			if (i < 2) {
				dp[i] = i;
			} else {
				int prev = i / 2;
				dp[i] = dp[prev] + (i % 2 == 0 ? 0 : dp[prev + 1]);
			}
			max = Math.max(max, dp[i]);
		}

		return max;
    }
}
