// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

package numberOfRectanglesThatCanFormTheLargestSquare;

class Solution {

	// time complexity: O(n)
	// space comlexity: O(1)
    public int countGoodRectangles(int[][] rectangles) {
		int cnt = 0;
		int maxlen = 0;
		for (var rec : rectangles) {
			int max = Math.min(rec[0], rec[1]);
			if (maxlen < max) {
				cnt = 1;
				maxlen = max;
			} else if (max == maxlen) {
				cnt++;
			}
		}

		return cnt;
    }
}
