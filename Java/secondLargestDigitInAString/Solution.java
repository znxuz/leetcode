// https://leetcode.com/problems/second-largest-digit-in-a-string/

package secondLargestDigitInAString;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int secondHighest(String s) {
		int max = -1;
		int sec = -1;
		for (var c : s.toCharArray()) {
			if (Character.isDigit(c)) {
				int cur = c - '0';
				if (cur > max) {
					sec = max;
					max = cur;
				} else if (cur < max) {
					sec = Math.max(sec, cur);
				}
			}
		}

		return sec;
    }
}
