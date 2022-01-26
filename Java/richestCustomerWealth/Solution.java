// https://leetcode.com/problems/richest-customer-wealth/

package richestCustomerWealth;

import java.util.Arrays;

class Solution {

    public int maximumWealth(int[][] accounts) {
		return Arrays.stream(accounts)
			.mapToInt(acc -> Arrays.stream(acc).sum())
			.max()
			.getAsInt();
	}

    public int maximumWealthLinear(int[][] accounts) {
		int max = 0;
		for (var acc : accounts) {
			int sum = 0;
			for (int m : acc)
				sum += m;
			max = Math.max(max ,sum);
		}

		return max;
    }
}
