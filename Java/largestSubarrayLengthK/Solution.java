// https://leetcode.com/problems/largest-subarray-length-k/

package largestSubarrayLengthK;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] largestSubarray(int[] nums, int k) {
		int maxIdx = -1;
		int max = 0;
		for (int i = nums.length - k; i >= 0; --i) {
			if (nums[i] > max) {
				max = nums[i];
				maxIdx = i;
			}
		}
		int[] ret = new int[k];
		int idx = 0;
		for (int i = maxIdx; i < maxIdx + k; ++i) {
			ret[idx++] = nums[i];
		}

		return ret;
    }
}
