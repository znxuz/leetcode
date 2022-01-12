// https://leetcode.com/problems/running-sum-of-1d-array/

package runningSumOf1DArray;

import java.util.stream.IntStream;

class Solution {

    public int[] runningSum(int[] nums) {
		IntStream.range(0, nums.length).forEach(i -> nums[i] += (i == 0) ? 0 : nums[i - 1]);
		return nums;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] runningSumLinear(int[] nums) {
		for (int i = 1; i < nums.length; ++i) {
			nums[i] += nums[i - 1];
		}

		return nums;
    }
}
