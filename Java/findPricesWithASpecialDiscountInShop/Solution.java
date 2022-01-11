// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

package findPricesWithASpecialDiscountInShop;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

	// stack
	// time complexity: O(n)
	// space complexity: O(n)
    public int[] finalPrices(int[] prices) {
		Deque<Integer> stack = new ArrayDeque<>();
		int n = prices.length;
		for (int i = n - 1; i >= 0; --i) {
			int prev = prices[i];
			while (!stack.isEmpty() && stack.peekLast() > prices[i])
				stack.pollLast();
			if (!stack.isEmpty())
				prices[i] -= stack.peekLast();
			stack.offerLast(prev);
		}

		return prices;
	}

	// time complexity: O(n^2)
	// space complexity: O(1)
    public int[] finalPricesN2(int[] prices) {
		int n = prices.length;
		int[] nextMins = new int[n];
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) {
				nextMins[i] = -1;
			} else if (prices[i + 1] <= prices[i]) {
				nextMins[i] = prices[i + 1];
			} else {
				int next = nextMins[i + 1];
				for (int j = i + 1; j < n; ++j) {
					next = Math.min(next, nextMins[j]);
					if (next <= prices[i])
						break;
				}
				nextMins[i] = next;
			}
		}

		for (int i = 0; i < n; ++i) {
			nextMins[i] = prices[i] - ((nextMins[i] == -1) ? 0 : nextMins[i]);
		}

		return nextMins;
    }
}
