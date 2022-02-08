// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

package longestContiguousSegmentsOfOnesThanZeros;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean checkZeroOnes(String s) {
		int ones = 0;
		int maxOnes = 0;
		int zeros = 0;
		int maxZeros = 0;
		for (char c : s.toCharArray()) {
			if (c == '0') {
				maxZeros = Math.max(maxZeros, ++zeros);
				maxOnes = Math.max(maxOnes, ones);
				ones = 0;
			} else {
				maxOnes = Math.max(maxOnes, ++ones);
				maxZeros = Math.max(maxZeros, zeros);
				zeros = 0;
			}
		}

		return maxOnes > maxZeros;
    }
}
