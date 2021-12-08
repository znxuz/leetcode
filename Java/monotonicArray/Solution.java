// https://leetcode.com/problems/monotonic-array/

package monotonicArray;

class Solution {

	// time complexity: O(n)
	// space compleixty: O(1)
    public boolean isMonotonic(int[] nums) {
		int growth = 0;
		for (int i = 1; i < nums.length; i++) {
			if (growth == 0)
				growth = nums[i] - nums[i - 1];
			else if ((growth < 0 && nums[i] - nums[i - 1] > 0) ||
					(growth > 0 && nums[i] - nums[i - 1] < 0))
				return false;

		}

		return true;
    }
}
