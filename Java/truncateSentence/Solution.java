// https://leetcode.com/problems/truncate-sentence/

package truncateSentence;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public String truncateSentence(String s, int k) {
		int i = 0;
		while (i < s.length() && k > 0) {
			if (i < s.length() - 1 && s.charAt(i + 1) == ' ')
				k--;
			i++;
			if (k == 0)
				break;
		}

		return s.substring(0, i);
    }
}
