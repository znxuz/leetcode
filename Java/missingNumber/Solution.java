// https://leetcode.com/problems/missing-number/

package missingNumber;

import java.util.Arrays;

class Solution {

	// TODO XOR operation

	// time complexity: O(n)
	// space complexity: O(1)
    public int missingNumber(int[] nums) {
		int sum = 0;
		int expected = nums.length * (nums.length + 1) / 2;

		for (int i = 0; i < nums.length; i++)
			sum += nums[i];

		return expected - sum;
	}

	// time complexity: O(n*log(n))
	// space complexity: O(1)
    public int missingNumberSort(int[] nums) {
		Arrays.sort(nums);
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] != i)
				return i;
		}

		return nums[nums.length - 1] + 1;
    }
}
