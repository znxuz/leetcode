// https://leetcode.com/problems/arranging-coins/

package arrangingCoins;

class Solution {

	// time complexity: O(log(n))
    public int arrangeCoins(int n) {
		int l = 0;
		int r = n;
		while (l <= r) {
			int m = l + (r - l) / 2;
			long cur = (long)m * (m + 1) / 2;
			if (cur == n)
				return m;
			if (cur < n)
				l = m + 1;
			else
				r = m - 1;
		}

		return r;
	}

	// time complexity: O(1)
    public int arrangeCoinsFormula2(int n) {
		return (int)(Math.sqrt(2 * (long)n + 0.25) - 0.5);
	}

	// time complexity: O(1)
    public int arrangeCoinsFormula1(int n) {
		return (int)((Math.sqrt(8 * (double)n + 1) - 1) / 2);
	}

	// time complexity: O(n)
    public int arrangeCoinsN(int n) {
		int counter = 0;
		while (n >= counter + 1)
			n -= ++counter;

		return counter;
    }
}
