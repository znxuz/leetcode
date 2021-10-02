// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

package bestTimeBuySellStock;

import static java.lang.Math.min;
import static java.lang.Math.max;

class Solution {

	// Kadane's Algorithm: max sub-array problem
	// time complexity: O(n)
	// space complexity: O(1)
    public int maxProfit(int[] prices) {
		int maxSoFar, max;
		maxSoFar = max = 0;

		for (int i = 1; i < prices.length; i++) {
			maxSoFar += prices[i] - prices[i - 1];
			maxSoFar = maxSoFar < 0 ? 0 : maxSoFar;
			max = max(max, maxSoFar);
		}

		return max;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxProfitOnePass(int[] prices) {
		if (prices == null)
			return 0;

		int buy, profit;
		buy = prices[0];
		profit = 0;
		for (int i = 1; i < prices.length; i++) {
			buy = min(buy, prices[i]);
			profit = max(profit, prices[i] - buy);
		}

		return profit;
    }
}
