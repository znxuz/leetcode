// https://leetcode.com/problems/sort-array-by-increasing-frequency/

package sortArrayByIncreasingFrequency;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n logn)
	// space complexity: O(n)
    public int[] frequencySort(int[] nums) {
		// or use an array of size 201 because of constraints given
		Map<Integer, Integer> map = new HashMap<>();
		for (int n : nums) {
			map.put(n, map.getOrDefault(n, 0) + 1);
		}

		return Arrays.stream(nums)
			.boxed()
			.sorted((i1, i2) -> {
				int cmp = Integer.compare(map.get(i1), map.get(i2));
				if (cmp == 0)
					return Integer.compare(i1, i2) * -1;
				return cmp;
			}).mapToInt(Integer::intValue).toArray();
    }
}
