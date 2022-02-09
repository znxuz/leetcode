// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

package removeOneElementToMakeTheArrayStrictlyIncreasing;

class Solution {

	// one pass
    public boolean canBeIncreasing(int[] nums) {
		int cnt = 0;
		for (int i = 1; i < nums.length; ++i) {
			if (nums[i] <= nums[i - 1]) {
				cnt++;
				if (i > 1 && nums[i] <= nums[i - 2])
					nums[i] = nums[i - 1];
			}
		}
		return cnt < 2;
	}

	// two passes
	// time complexity: O(n)
	// space complexity: O(1)
    public boolean canBeIncreasingTwoPasses(int[] nums) {
		int n = nums.length;
		int forward = 0;
		int backward = 0;
		int prev = nums[0];

		for (int i = 1; i < n; ++i) {
			if (nums[i] <= prev)
				forward++;
			else
				prev = nums[i];
		}
		prev = nums[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			if (nums[i] >= prev)
				backward++;
			else
				prev = nums[i];
		}

		return Math.min(forward, backward) <= 1;
    }

}
