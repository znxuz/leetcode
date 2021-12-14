// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

package nRepeatedElemInSize2DArray;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
	public int repeatedNTimes(int[] nums) {
		for (int i = 2; i < nums.length; ++i) {
			if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2])
				return nums[i];
		}

		return nums[0];
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int repeatedNTimesSet(int[] nums) {
		Set<Integer> set = new HashSet<>();
		for (int i : nums) {
			if (set.contains(i))
				return i;
			set.add(i);
		}

		return -1;
	}

}
