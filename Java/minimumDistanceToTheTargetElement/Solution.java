// https://leetcode.com/problems/minimum-distance-to-the-target-element/

package minimumDistanceToTheTargetElement;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int getMinDistance(int[] nums, int target, int start) {
		int res = nums.length;
		for (int i = 0; i < nums.length; ++i) {
			if (nums[i] == target)
				res = Math.min(res, Math.abs(start - i));
		}

		return res;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int getMinDistanceTwoPointer(int[] nums, int target, int start) {
		int left, right;
		left = right = start;
		while (left >= 0 || right < nums.length) {
			if (left >= 0 && nums[left] == target)
				return Math.abs(left - start);
			if (right < nums.length && nums[right] == target)
				return Math.abs(left - start);
			left--;
			right++;
		}

		return -1;
    }
}
