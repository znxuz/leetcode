// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

package minimumOperationsToMakeTheArrayIncreasing;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int minOperations(int[] nums) {
		int cnt = 0;
		for (int i = 0; i < nums.length - 1; ++i) {
			if (nums[i] >= nums[i + 1]) {
				int increase = nums[i] - nums[i + 1] + 1;
				cnt += increase;
				nums[i + 1] += increase;
			}
		}

		return cnt;
    }
}
