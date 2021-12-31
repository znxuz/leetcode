// https://leetcode.com/problems/unique-number-of-occurrences/

package uniqueNumberOfOccurrences;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean uniqueOccurrences(int[] arr) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int n : arr)
			map.put(n, map.getOrDefault(n, 0) + 1);
		return map.values().size() == new HashSet<>(map.values()).size();
	}

	// constraints: -1000 <= arr[i] <= 1000
	// time complexity: O(n)
	// space complexity: O(n)
    public boolean uniqueOccurrencesCountingSort(int[] arr) {
		int[] negativesCtr = new int[1001];
		int[] neutralsCtr = new int[1001];
		for (int n : arr) {
			if (n < 0)
				negativesCtr[Math.abs(n)]++;
			else
				neutralsCtr[n]++;
		}
		int[] occurrences = new int[2002];
			// can be replaced by a hash set
		for (int ctr : negativesCtr) {
			if (ctr == 0)
				continue;
			if (occurrences[ctr] != 0)
				return false;
			occurrences[ctr]++;
		}
		for (int ctr : neutralsCtr) {
			if (ctr == 0)
				continue;
			if (occurrences[ctr] != 0)
				return false;
			occurrences[ctr]++;
		}

		return true;
    }
}
