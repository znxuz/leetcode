// https://leetcode.com/problems/single-number/

package singleNumber;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

	private final Set<Integer> set = new HashSet<>();

    public int singleNumberSet(int[] nums) {
		if (nums == null)
			return 0;

		for (int i = 0; i < nums.length; i++) {
			int current = nums[i];
			if (!set.contains(current)) {
				set.add(current);
			} else {
				set.remove(current);
			}
		}

		return set.iterator().next();
    }

	public int singleNumberMath(int[] nums) {
		int sum = Arrays.stream(nums).reduce(0, Math::addExact);
		int distinctSumTimes2 = Arrays.stream(nums).distinct().reduce(0, Math::addExact) * 2;
		return distinctSumTimes2 - sum;
	}

	public int singleNumber(int[] nums) {
		/* one liner
		return Arrays.stream(nums).reduce(0, (a, b) -> a ^ b);
		*/
		int rest = 0;
		for (int i : nums) {
			rest ^= i;
		}

		return rest;
	}
}
