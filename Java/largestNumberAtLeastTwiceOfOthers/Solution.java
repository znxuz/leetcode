// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

package largestNumberAtLeastTwiceOfOthers;

class Solution {

	// time complexity: O(n)
	// spcae complexity: O(1)
    public int dominantIndex(int[] nums) {
        int max = -1, index = -1, second = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max) {
                second = max;
                max = nums[i];
                index = i;
            } else if (nums[i] > second)
                second = nums[i];
        }

        return second * 2 <= max ? index : -1;
    }
}
