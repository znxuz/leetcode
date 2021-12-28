// https://leetcode.com/problems/rank-transform-of-an-array/

package rankTransformOfAnArray;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n logn)
	// space complexity: O(n)
    public int[] arrayRankTransform(int[] arr) {
		int[] sorted = Arrays.copyOf(arr, arr.length);
		Arrays.sort(sorted);
		Map<Integer, Integer> map = new HashMap<>();
		for (int n : sorted)
			map.putIfAbsent(n, map.size() + 1);
		for (int i = 0; i < arr.length; ++i) {
			arr[i] = map.get(arr[i]);
		}

		return arr;
    }
}
