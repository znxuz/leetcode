// https://leetcode.com/problems/majority-element/

package majorityElement;

import java.util.Arrays;

class Solution {

	// Boyer-Moore Voting Algorithm:
		// reset max if count == 0, inc count if cur == max, else dec
	// time complexity: O(n)
	// space complexity: O(1)
    public int majorityElement(int[] nums) {
		if (nums == null)
			return -1;

		int max = nums[0];
		int count = 1;
		for (int num : nums) {
			if (num == max)
				count++;
			else if (count - 1 == 0)
				max = num;
			else
				count--;
		}

		return max;
	}

	private int countMajority(int[] nums, int left, int right, int target) {
		int count = 0;
		for (int i = left; i <= right; i++)
			count = nums[i] == target ? count + 1 : count;
		return count;
	}

	// time complexity: O(n * log_2(n)), log(n) binary search, n for counting
	// space complexity: O(log_2(n)) for recursions
	private int majorityElementRec(int[] nums, int left, int right) {
		if (left == right)
			return nums[left];

		int mid = left + (right - left) / 2;
		int leftMax = majorityElementRec(nums, left, mid);
		int rightMax = majorityElementRec(nums, mid + 1, right);

		if (leftMax == rightMax)
			return leftMax;
		return countMajority(nums, left, mid, leftMax)
			> countMajority(nums, mid + 1, right, rightMax) ? leftMax : rightMax;
	}

    public int majorityElementRecursive(int[] nums) {
		return majorityElementRec(nums, 0, nums.length - 1);
	}

    public int majorityElementAlter(int[] nums) {
		Arrays.sort(nums);
		return nums[(nums.length - 1) / 2];
    }
}
