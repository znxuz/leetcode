// https://leetcode.com/problems/divisor-game/

package divisorGame;

class Solution {

	public boolean divisorGameRec(int n) {
		if (n == 1)
			return false;
		if (n == 2)
			return true;
		return divisorGameRec(n - 2);
	}

	// dynamic programming
	// time complexity: O(n)
	// space complexity: O(n)
    public boolean divisorGameDP(int n) {
		boolean[] dp = new boolean[n + 1];
		for (int i = 1; i < dp.length; i++) {
			if (i == 1)
				dp[i] = false;
			else if (i == 2)
				dp[i] = true;
			else
				dp[i] = dp[i - 2];
		}
		return dp[n];
	}

	// 1 -> false
	// 2 -> true
	// 3 -> false
	// 4 -> true
	// 5 -> false
	// 6 -> true
	// 7 -> false
	// 8 -> true
	// 9 -> false
	// 10 -> true
	// 11 ->
	// 12 ->
	// 13 ->
	// 14 ->
	// 15 ->
    public boolean divisorGameMod(int n) {
		return n % 2 == 0;
    }

}
