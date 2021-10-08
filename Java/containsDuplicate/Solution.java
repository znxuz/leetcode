// https://leetcode.com/problems/contains-duplicate/

package containsDuplicate;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

class Solution {

    public boolean containsDuplicate(int[] nums) {
		return containsDuplicateSort(nums);
	}

	// time complexity: O(n * log(n))
	// space complexity: O(11)
	// fastest 3ms
	private boolean containsDuplicateSort(int[] nums) {
		Arrays.sort(nums);
		for (int i = 0; i < nums.length - 1; i++) {
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}

	// time complexity: O(n) * O(1) hashmap contains
	// space complexity: O(n)
	// average 6ms
    public boolean containsDuplicateSet(int[] nums) {
		Set<Integer> set = new HashSet<>();
		for (var num : nums) {
			if (set.contains(num))
				return true;
			set.add(num);
		}
		return false;
	}

    public boolean containsDuplicateStream(int[] nums) {
		// 5ms
		return !(Arrays.stream(nums)
				.boxed()
				.collect(Collectors.toSet()).size() == nums.length);
		// 7ms
		// return !(Arrays.stream(nums).distinct().count() == nums.length);
    }
}
