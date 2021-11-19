// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

package longestContinuousIncreasingSubsequence;

class Solution {

	// sliding window algorithm
	// time complexity: O(n)
	// space complexity: O(1)
    public int findLengthOfLCIS(int[] nums) {
		int len = 0;
		int anchor = 0;
		for (int i = 0; i < nums.length; i++) {
			if (i > 0 && nums[i - 1] >= nums[i])
				anchor = i;
			len = Math.max(len, i - anchor + 1);
		}

		return len;
	}

	// time complexity: O(n)
	// spcae complexity: O(1)
    public int findLengthOfLCISMine(int[] nums) {
		int len = 0;
		for (int i = 0; i < nums.length; i++) {
			int count = 1;
			while (i + 1 < nums.length && nums[i + 1] > nums[i]) {
				count++;
				i++;
			}
			len = Math.max(len, count);
		}

		return len;
    }
}
