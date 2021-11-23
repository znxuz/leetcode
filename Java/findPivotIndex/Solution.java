// https://leetcode.com/problems/find-pivot-index/

package findPivotIndex;

class Solution {

	// sliding window algorithm
	// time complexity: 2n = O(n)
	// space complexity: O(1)
    public int pivotIndex(int[] nums) {
		int right = 0;
		for (int num : nums)
			right += num;

		int left = 0;
		for (int i = 0; i < nums.length; i++) {
			if (left == right - nums[i])
				return i;
			left += nums[i];
			right -= nums[i];
		}

		return -1;
    }
}
