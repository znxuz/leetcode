// https://leetcode.com/problems/di-string-match/

package dIStringMatch;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] diStringMatch(String s) {
		int[] ret = new int[s.length() + 1];
		int dCounter = s.length();
		int iCounter = 0;
		for (int i = 0; i < ret.length; ++i) {
			if (i == s.length())
				ret[i] = s.charAt(i - 1) == 'D' ? iCounter : dCounter;
			else
				ret[i] = s.charAt(i) == 'D' ? dCounter-- : iCounter++;
		}

		return ret;
    }
}
