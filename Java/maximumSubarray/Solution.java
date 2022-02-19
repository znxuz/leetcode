// https://leetcode.com/problems/maximum-subarray/

package maximumSubarray;

class Solution {

	public int maxSubArray(int[] nums) {
		return maxSubArrayRec(nums, 0, nums.length - 1);
	}

	public int maxSubArrayRec(int[] nums, int left, int right) {
		if (left == right)
			return nums[left];

		int mid = left + (right - left) / 2;
		return Math.max(maxCrossArray(nums, left, mid, right),
				Math.max(maxSubArrayRec(nums, left, mid), maxSubArrayRec(nums, mid + 1, right)));
	}

	private int maxCrossArray(int[] nums, int left, int mid, int right) {
		int leftSum, rightSum;
		leftSum = rightSum = Integer.MIN_VALUE;

		for (int i = mid, sum = 0; i >= left; i--) {
			sum += nums[i];
			leftSum = Math.max(sum, leftSum);
		}
		for (int i = mid + 1, sum = 0; i <= right; i++) {
			sum += nums[i];
			rightSum = Math.max(sum, rightSum);
		}

		return leftSum + rightSum;
	}

	// Kadane's algorithm
    public int maxSubArrayKadane(int[] nums) {
		int max = 0;
		int sum = 0;
		for (int i = 0; i < nums.length; i++) {
			sum = Math.max(nums[i], sum + nums[i]);
			max = Math.max(max, sum);
		}

		return max;
    }
}
