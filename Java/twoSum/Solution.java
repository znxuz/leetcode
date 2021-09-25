// https://leetcode.com/problems/two-sum/

package twoSum;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// O(n^2)
    public int[] twoSum(int[] nums, int target) {
		for (int i = 0; i < nums.length; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (nums[i] + nums[j] == target)
					return new int[]{i, j};
			}
		}

		return null;
    }

	// O(n)
	public int[] twoSumImproved(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<>();

		for (int i = 0; i < nums.length; i++) {
			int complement = target - nums[i];
			if (map.containsKey(complement))
				return new int[]{i, map.get(complement)};
			map.put(nums[i], i);
		}

		return null;
	}
}
