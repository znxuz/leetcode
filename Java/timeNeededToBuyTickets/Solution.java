// https://leetcode.com/problems/time-needed-to-buy-tickets/

package timeNeededToBuyTickets;

class Solution {

    public int timeRequiredToBuy(int[] tickets, int k) {
		int cnt = 0;
		for (int i = 0; i < tickets.length; ++i)
			cnt += Math.min((i <= k) ? tickets[k] : tickets[k] - 1, tickets[i]);

		return cnt;
    }
}
