// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/

package checkWetherTwoStringsAreAlmostEquivalent;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean checkAlmostEquivalent(String word1, String word2) {
		int[] cnts = new int[26];
		for (int i = 0; i < word1.length(); ++i) {
			cnts[word1.charAt(i) - 'a']++;
			cnts[word2.charAt(i) - 'a']--;
		}

		for (int i = 0; i < cnts.length; ++i)
			if (cnts[i] < -3 || cnts[i] > 3)
				return false;
		return true;
    }
}
