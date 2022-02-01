// https://leetcode.com/problems/merge-strings-alternately/

package mergeStringAlternately;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String mergeAlternately(String word1, String word2) {
		var strBuilder = new StringBuilder();
		int i = 0;
		int j = 0;
		while (i < word1.length() && j < word2.length()) {
			if (i <= j)
				strBuilder.append(word1.charAt(i++));
			else
				strBuilder.append(word2.charAt(j++));
		}
		while (i < word1.length())
			strBuilder.append(word1.charAt(i++));
		while (j < word2.length())
			strBuilder.append(word2.charAt(j++));

		return strBuilder.toString();
    }
}
