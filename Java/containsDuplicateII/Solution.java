package containsDuplicateII;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n) * O(1) contains
	// space complexity: O(n)
	// from 25.09.2021
	public boolean containsNearbyDuplicate(int[] nums, int k) {
		Set<Integer> set = new HashSet<>();
		for (int i = 0; i < nums.length; ++i) {
			if (set.contains(nums[i])) return true;
			set.add(nums[i]);
			if (set.size() > k) {
				set.remove(nums[i - k]);
			}
		}
		return false;
	}
}
