// https://leetcode.com/problems/smallest-range-i/

package smallestRange;

class Solution {

    public int smallestRangeI(int[] nums, int k) {
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int i : nums) {
			min = Math.min(min, i);
			max = Math.max(max, i);
		}

		return Math.max(0, max - min - 2 * k);
    }
}
