// https://leetcode.com/problems/kth-distinct-string-in-an-array/

package kthDistinctStringInAnArray;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n * m)
	// space complexity: O(n)
    public String kthDistinctMap(String[] arr, int k) {
		Map<String, Integer> map = new HashMap<>();
		for (var s : arr)
			map.put(s, map.getOrDefault(s, 0) + 1);
		for (var s : arr) {
			if (map.get(s) == 1)
				k--;
			if (k == 0)
				return s;
		}
		return "";
    }
}
