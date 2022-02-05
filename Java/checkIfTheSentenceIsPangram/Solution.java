// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

package checkIfTheSentenceIsPangram;

class Solution {

	// time complexity; O(n)
	// space complexity: O(1)
    public boolean checkIfPangram(String sentence) {
		int seen = 0;
		for (char c : sentence.toCharArray())
			seen |= 1 << (c - 'a');
		return seen == (1 << 26) - 1;
	}

	// time complexity: O(n)
	// space complexity: O(26)
    public boolean checkIfPangramArray(String sentence) {
		int[] cnts = new int[26];
		for (char c : sentence.toCharArray())
			cnts[c - 'a']++;
		for (var c : cnts)
			if (c == 0)
				return false;
		return true;
    }
}
