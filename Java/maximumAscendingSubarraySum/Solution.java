// https://leetcode.com/problems/maximum-ascending-subarray-sum/

package maximumAscendingSubarraySum;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxAscendingSum(int[] nums) {
		int prev = 0;
		int sum = 0;
		int max = 0;
		for (int i = 0; i < nums.length; ++i) {
			if (nums[i] > prev) {
				sum += nums[i];
			} else {
				max = Math.max(max, sum);
				sum = 0;
			}
			sum += nums[i];
			prev = nums[i];
		}

		return Math.max(max ,sum);
    }
}
