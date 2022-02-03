// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

package checkIfBinaryStringHasAtMostOneSegmentOfOnes;

class Solution {

    public boolean checkOnesSegment(String s) {
		return !ts.contains("01");
	}

    public boolean checkOnesSegmentLinearScan(String s) {
		boolean zero = false;
		for (int i = 0; i < s.length(); ++i) {
			if (!zero && s.charAt(i) == '0')
				zero = true;
			else if (zero && s.charAt(i) == '1')
				return false;
		}

		return true;
    }
}
