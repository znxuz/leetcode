// https://leetcode.com/problems/min-cost-climbing-stairs/

package minCostClimbingStairs;

class Solution {

    public int minCostClimbingStairs(int[] cost) {
		return constantSpaceDP(cost);
	}

	// constant-space dynamic programming
	// time complexity: O(n)
	// space complexity: O(1)
	public int constantSpaceDP(int[] cost) {
		int prev2 = cost[0];
		int prev1 = cost[1];
		for (int i = 2; i < cost.length; i++) {
			int cur = Math.min(prev1, prev2) + cost[i];
			prev2 = prev1;
			prev1 = cur;
		}

		return Math.min(prev1, prev2);
	}

	// bottom-up dynamic programming:
	// 	recurrence relation
	// crazy that i did it first try right?
	// 	(although I tested it twice just to be sure)
	// time complexity: O(n)
	// space complexity: O(n)
    public int dpBottomUp(int[] cost) {
		int[] dp = new int[cost.length];

		for (int i = 0; i < dp.length; i++) {
			if (i < 2) {
				dp[i] = cost[i];
				continue;
			}
			dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
		}

		return Math.min(dp[dp.length - 2], dp[dp.length - 1]);
    }

	// top-down memoization with recursion
	// time complexity: O(n)
	// spcae complexity: O(n)
	private int dpTopDown(int[] cost, int[] dp, int i) {
		if (i < 2) {
			dp[i] = cost[i];
			return dp[i];
		}

		dp[i - 1] = dp[i - 1] == 0 ? dpTopDown(cost, dp, i - 1) : dp[i - 1];
		dp[i - 2] = dp[i - 2] == 0 ? dpTopDown(cost, dp, i - 2) : dp[i - 2];

		return Math.min(dp[i - 2], dp[i - 1]) + (i < cost.length ? cost[i] : 0);
	}

}
