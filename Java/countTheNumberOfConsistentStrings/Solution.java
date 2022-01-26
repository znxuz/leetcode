// https://leetcode.com/problems/count-the-number-of-consistent-strings/

package countTheNumberOfConsistentStrings;

class Solution {

	// time compleixty: O(n)
	// space complexity: O(1)
    public int countConsistentStrings(String allowed, String[] words) {
		boolean[] flags = new boolean[26];
		for (char c : allowed.toCharArray())
			flags[c - 'a'] = true;

		int cnt = 0;
		for (var w : words) {
			int i = 0;
			while (i < w.length()) {
				if (!flags[w.charAt(i) - 'a'])
					break;
				i++;
			}
			if (i == w.length())
				cnt++;
		}

		return cnt;
    }

}
