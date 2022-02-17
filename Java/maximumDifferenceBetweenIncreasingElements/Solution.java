// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

package maximumDifferenceBetweenIncreasingElements;

class Solution {

    public int maximumDifference(int[] nums) {
		int max = nums[nums.length - 1];
		int diff = -1;
		for (int i = nums.length - 1; i >= 0; --i) {
			if (nums[i] >= max)
				max = nums[i];
			else
				diff = Math.max(diff, max - nums[i]);
		}

		return diff;
    }
}
