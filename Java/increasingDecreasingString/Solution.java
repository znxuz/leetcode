// https://leetcode.com/problems/increasing-decreasing-string/

package increasingDecreasingString;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public String sortString(String s) {
		int[] chars = new int[26];
		for (char c : s.toCharArray())
			chars[c - 'a']++;

		var stringBuilder = new StringBuilder();
		while (stringBuilder.length() != s.length()) {
			for (int i = 0; i < chars.length; ++i) {
				if (chars[i] != 0) {
					stringBuilder.append((char)(i + 'a'));
					chars[i]--;
				}
			}
			for (int i = chars.length - 1; i >= 0; --i) {
				if (chars[i] != 0) {
					stringBuilder.append((char)(i + 'a'));
					chars[i]--;
				}
			}
		}

		return stringBuilder.toString();
    }
}
