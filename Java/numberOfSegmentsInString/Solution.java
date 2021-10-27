// https://leetcode.com/problems/number-of-segments-in-a-string/

package numberOfSegmentsInString;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int countSegments(String s) {
		int count = 0;
		boolean isPrevSpace = true;
		for (char c : s.toCharArray()) {
			if (c == ' ') {
				isPrevSpace = true;
			} else {
				if (isPrevSpace)
					count++;
				isPrevSpace = false;
			}
		}

		return count;
    }
}
