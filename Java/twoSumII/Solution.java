// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

package twoSumII;

class Solution {
		
	// time complexity: O(n)
	// space complexity: O(1)
    public int[] twoSum(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;

		while (left < right) {
			int mid = left + (right - left) / 2;
			int sum = nums[left] + nums[right];
			if (sum == target)
				return new int[]{left + 1, right + 1};
			if (sum < target)
				left = nums[mid] + nums[right] < sum ? mid : left + 1;
			else
				right = nums[left] + nums[mid] > sum ? mid : right - 1;
		}

		return null;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] twoSumLinear(int[] nums, int target) {
		if (nums == null)
			return null;

		int left = 0;
		int right = nums.length - 1;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum == target)
				return new int[]{left + 1, right + 1};
			else if (sum < target)
				left++;
			else
				right--;
		}

		return null;
    }
}
