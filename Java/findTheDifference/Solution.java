// https://leetcode.com/problems/find-the-difference/

package findTheDifference;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public char findTheDifference(String s, String t) {
		char res = 0;
		for (char c : s.toCharArray())
			res ^= c;
		for (char c : t.toCharArray())
			res ^= c;
		return res;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public char findTheDifferenceArray(String s, String t) {
		int[] alpha = new int[26];
		for (char c : t.toCharArray())
			alpha[c - 'a']++;
		for (char c : s.toCharArray())
			alpha[c - 'a']--;

		for (int i = 0; i < alpha.length; i++) {
			if (alpha[i] == 1)
				return (char)(i + 'a');
		}

		return 0;
    }
}
