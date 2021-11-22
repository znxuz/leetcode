// https://leetcode.com/problems/degree-of-an-array/

package degreeOfAnArray;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int findShortestSubArrayHashMap(int[] nums) {
		Map<Integer, Integer> count = new HashMap<>(), first = new HashMap<>();
		int degree = 0, result = 0;
		for (int i = 0; i < nums.length; i++) {
			first.putIfAbsent(nums[i], i);
			int currentDegree = count.getOrDefault(nums[i], 0) + 1;
			count.put(nums[i], currentDegree);
			if (currentDegree > degree) {
				degree = currentDegree;
				result = i - first.get(nums[i]);
			} else if (currentDegree == degree) {
				result = Math.min(result, i - first.get(nums[i]));
			}
		}

		return result + 1;
    }
}
