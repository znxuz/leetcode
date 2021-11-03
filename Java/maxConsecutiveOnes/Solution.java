// https://leetcode.com/problems/max-consecutive-ones/

package maxConsecutiveOnes;

class Solution {

    public int findMaxConsecutiveOnes(int[] nums) {
		int maxCurrent = 0;
		int maxGlobal = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == 1) {
				maxCurrent++;
			} else {
				maxGlobal = Math.max(maxCurrent, maxGlobal);
				maxCurrent = 0;
			}
		}

		return Math.max(maxCurrent, maxGlobal);
    }
}
