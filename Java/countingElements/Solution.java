// https://leetcode.com/problems/counting-elements/

package countingElements;

import java.util.Map;
import java.util.TreeMap;

class Solution {

	// time complexity: O(n logn)
	// space complexity: O(n)
	public int countElements(int[] arr) {
		Map<Integer, Integer> map = new TreeMap<>();
		for (int n : arr)
			map.put(n, map.getOrDefault(n, 0) + 1);
		int total = 0;
		int prev = -1;
		int prevCount = -1;
		for (var entry : map.entrySet()) {
			int cur = entry.getKey();
			int count = entry.getValue();
			if (prev != -1 && cur == prev + 1)
				total += prevCount;
			prev = cur;
			prevCount = count;
		}

		return total;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int countElementsCountingSort(int[] arr) {
		int[] ctr = new int[1001];
		int max = arr[0];
		for (int n : arr) {
			ctr[n]++;
			max = Math.max(max, n);
		}

		int count = 0;
		for (int i = 0; i <= max; ++i) {
			if (ctr[i] == 0 || i == max || ctr[i + 1] == 0)
				continue;
			count += ctr[i];
		}

		return count;
    }
}
