// https://leetcode.com/problems/maximum-average-subarray-i/

package maximumAverageSubarrayI;

class Solution {

	// Sliding window algorithm
	// time complexity: O(n)
	// space complexity: O(1)
    public double findMaxAverage(int[] nums, int k) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}

		int max = sum;
		for (int i = k; i < nums.length; i++) {
			sum += nums[i] - nums[i - k];
			max = Math.max(max, sum);
		}

		return (double)max / k;
    }
}
