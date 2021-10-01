// https://leetcode.com/problems/maximum-subarray/

package maximumSubarray;

import static java.lang.Math.max;

class Solution {

	// fixme
	private int maxCrossArray(int[] nums, int left, int mid, int right) {
		int sum, leftSum, rightSum;
		sum = leftSum = rightSum = 0;

		for (int i = left; i <= mid; i++) {
			sum += nums[i];
			leftSum = max(sum, leftSum);
		}
		sum = 0;
		for (int i = mid + 1; i <= right; i++) {
			sum += nums[i];
			rightSum = max(sum, rightSum);
		}

		return max(max(leftSum, rightSum), leftSum + rightSum);
	}

	@SuppressWarnings("unused")
	private int maxSubArrayRec(int[] nums, int left, int right) {
		if (left == right)
			return nums[left];

		int mid = left + (right - left) / 2;
		return max(maxCrossArray(nums, left, mid, right),
				max(maxSubArrayRec(nums, left, mid), maxSubArrayRec(nums, mid + 1, right)));
	}

	// Kadane's algorithm
    public int maxSubArray(int[] nums) {
		if (nums.length == 0)
			return 0;

		int maxSoFar, maxEndingHere;
		maxSoFar = maxEndingHere = nums[0];
		for (int i = 1; i < nums.length; i++) {
			maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
			maxSoFar = max(maxSoFar, maxEndingHere);
		}

		return maxSoFar;
    }
}
