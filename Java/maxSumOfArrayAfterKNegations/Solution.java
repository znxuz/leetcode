// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

package maxSumOfArrayAfterKNegations;

import java.util.Arrays;

class Solution {

	// time complexity: O(n * logn)
	// space complexity: O(n) for sorting
    public int largestSumAfterKNegations(int[] nums, int k) {
		Arrays.sort(nums);
		for (int i = 0; i < nums.length && k > 0; ++i, --k) {
			if (nums[i] < 0) {
				nums[i] *= -1;
			} else if (nums[i] == 0 || k % 2 == 0) {
				k = 0;
			} else {
				if (nums[i] > (i == 0 ? nums[i] : nums[i - 1])) {
					while (k-- > 0)
						nums[i - 1] *= -1;
				} else {
					while (k-- > 0)
						nums[i] *= -1;
				}
			}
		}
		while (k-- > 0)
			nums[nums.length - 1] *= -1;

		int sum = 0;
		for (int i : nums)
			sum += i;
		return sum;
    }
}
