// https://leetcode.com/problems/n-th-tribonacci-number/

package nthTribonnaciNumber;

class Solution {

    public int tribonacci(int n) {
		return tribonacciConstSpace(n);
    }

	// time complexity: O(n)
	// space complexity: O(1)
	public int tribonacciConstSpace(int n) {
		if (n == 0)
			return 0;

		int a = 0;
		int b = 0;
		int c = 1;
		while (--n > 0) {
			int next = a + b + c;
			a = b;
			b = c;
			c = next;
		}

		return c;
	}

	// bottom up dynamic programming
	// time complexity: O(n)
	// space complexity: O(n)
	public int tribonacciIter(int n) {
		int[] dp = new int[n + 1];
		for (int i = 0; i < dp.length; ++i) {
			if (i < 2)
				dp[i] = i;
			else if (i == 2)
				dp[i] = 1;
			else
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		return dp[n];
	}

	// stack overflow
	public int tribonacciRec(int n) {
		if (n < 0)
			throw new IllegalArgumentException();
		if (n == 0)
			return 0;
		if (n < 3)
			return 1;
		return tribonacciRec(n - 1) + tribonacciRec(n - 2) + tribonacciRec(n - 3);
	}
}
