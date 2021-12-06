// https://leetcode.com/problems/lemonade-change/

package lemonadeChange;

class Solution {

    public boolean lemonadeChange(int[] bills) {
		int[] cash = new int[2];
		for (int bill : bills) {
			if (bill == 5) {
				cash[0]++;
			} else if (bill == 10) {
				if (cash[0] == 0)
					return false;
				cash[0]--;
				cash[1]++;
			} else {
				if (cash[1] > 0 && cash[0] > 0) {
					cash[0]--;
					cash[1]--;
				} else if (cash[0] > 2) {
					cash[0] -= 3;
				} else {
					return false;
				}
			}
		}

		return true;
    }
}
