// https://leetcode.com/problems/two-sum-less-than-k/

package twoSumLessThanK;

import java.util.Arrays;

class Solution {

	// time complexity: O(n * logn + n): O(nlog_n)
	// space complexity; O(n): sorting
    public int twoSumLessThanKSort(int[] nums, int k) {
		Arrays.sort(nums);
		int left = 0;
		int right = nums.length - 1;
		int sum = -1;
		while (left < right) {
			if (nums[left] + nums[right] >= k) {
				right--;
			} else {
				sum = Math.max(sum, nums[left] + nums[right]);
				left++;
			}
		}

		return sum;
    }
}
