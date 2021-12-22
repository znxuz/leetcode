// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

package checkIfNumIsMajorityInSortedArray;

import java.util.Arrays;

class Solution {

	// time complexity: O(logn)
	// space complexity: O(1)
    public boolean isMajorityElement(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (nums[left] != target)
			return false;

		return left + nums.length / 2 < nums.length
			&& nums[left] == nums[left + nums.length / 2];
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean isMajorityElementLoop(int[] nums, int target) {
		int ctr = 0;
		for (int n : nums) {
			if (n != target)
				continue;
			ctr++;
		}

		return ctr > nums.length / 2;
	}

    public boolean isMajorityElementStream(int[] nums, int target) {
		return Arrays.stream(nums).filter(n -> n == target).count() > nums.length / 2;
    }
}
