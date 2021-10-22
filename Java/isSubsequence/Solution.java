// https://leetcode.com/problems/is-subsequence/

package isSubsequence;

class Solution {

    public boolean isSubsequence(String s, String t) {
		return usingPointers(s, t);
    }

	// time complexity: O(m): m == t.length()
	// space complexity: O(1)
	private boolean usingPointers(String s, String t) {
		int i = 0;
		int j = 0;
		while (i < s.length() && j < t.length()) {
			if (s.charAt(i) == t.charAt(j))
				i++;
			j++;
		}

		return i == s.length();
	}

}
