// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

package maximumScoreAfterSplittingString;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxScore(String s) {
		int zeros = 0;
		int ones = 0;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == '0')
				zeros++;
			else
				ones++;
			if (i != s.length() - 1)
				max = Math.max(max, zeros - ones);
		}

		return max + ones;
    }
}
