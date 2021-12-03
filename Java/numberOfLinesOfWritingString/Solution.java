// https://leetcode.com/problems/number-of-lines-to-write-string/

package numberOfLinesOfWritingString;

class Solution {

	private final int limit = 100;

    public int[] numberOfLines(int[] widths, String s) {
		int count = 1;
		int width = 0;
		for (char c : s.toCharArray()) {
			int current = widths[c - 'a'];
			if (width + current > limit) {
				count++;
				width = 0;
			}
			width += current;
		}

		return new int[]{count, width};
    }
}
