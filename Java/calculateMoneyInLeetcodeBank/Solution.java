// https://leetcode.com/problems/calculate-money-in-leetcode-bank/submissions/

package calculateMoneyInLeetcodeBank;

class Solution {

	// https://leetcode.com/problems/calculate-money-in-leetcode-bank/discuss/1009192/C%2B%2B-O(1)-Math
    public int totalMoney(int n) {
		int f = n / 7, d = n % 7;
		return (49 + 7 * f) * f / 2 + (2 * f + d + 1) * d / 2;
	}

}
