// https://leetcode.com/problems/split-a-string-in-balanced-strings/

package splitStringInBalancedStrings;

class Solution {

	// greedy algorithm
	// time complexity: O(n)
	// space complexity: O(1)
    public int balancedStringSplit(String s) {
		int ctr = 0;
		int ret = 0;
		for (int i = 0; i < s.length(); ++i) {
			ctr += (s.charAt(i) == 'L') ? 1 : -1;
			if (ctr == 0)
				ret++;
		}

		return ret;
	}
}
