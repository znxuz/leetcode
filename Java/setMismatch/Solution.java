// https://leetcode.com/problems/set-mismatch/

package setMismatch;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] findErrorNumsConstantSpcae(int[] nums) {
		int dup, missing;
		dup = missing = -1;
		for (int i : nums) {
			if (nums[Math.abs(i) - 1] < 0)
				dup = Math.abs(i);
			else
				nums[Math.abs(i) - 1] *= -1;
		}
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] > 0)
				missing = i + 1;
		}

		return new int[]{dup, missing};
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int[] findErrorNumsExtraArray(int[] nums) {
		int[] ret = new int[2];
		boolean[] flags = new boolean[nums.length];
		for (int i : nums) {
			if (flags[i - 1])
				ret[0] = i;
			else
				flags[i - 1] = true;
		}

		for (int i = 0; i < flags.length; i++) {
			if (!flags[i])
				ret[1] = i + 1;
		}
		return ret;
	}

	// time complexity: O(n * logn)
	// space complexity: O(logn) for sorting
    public int[] findErrorNumsSort(int[] nums) {
		Arrays.sort(nums);
		int[] ret = new int[2];
		int counter = 1;
		for (int i = 0; i < nums.length; i++) {
			if (counter > nums[i]) {
				ret[0] = nums[i];
				counter--;
			} else if (counter < nums[i]) {
				ret[1] = counter;
				counter++;
			}
			counter++;
		}

		if (ret[1] == 0)
			ret[1] = nums.length;
		return ret;
    }
}
