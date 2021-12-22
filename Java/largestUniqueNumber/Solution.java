// https://leetcode.com/problems/largest-unique-number/

package largestUniqueNumber;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int largestUniqueNumber(int[] nums) {
		int[] ranks = new int[1001];
		for (int n : nums)
			ranks[n]++;
		for (int i = ranks.length - 1; i >= 0; --i) {
			if (ranks[i] == 1)
				return i;
		}

		return -1;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int largestUniqueNumberSet(int[] nums) {
		Set<Integer> set = new HashSet<>();
		Set<Integer> repeated = new HashSet<>();
		for (int n : nums) {
			if (!repeated.contains(n)) {
				set.add(n);
				repeated.add(n);
			} else {
				set.remove(n);
			}
		}

		int max = -1;
		for (var iter = set.iterator(); iter.hasNext();) {
			max = Math.max(max, iter.next());
		}

		return max;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int largestUniqueNumberMap(int[] nums) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i : nums)
			map.put(i, map.getOrDefault(i, 0) + 1);

		int max = -1;
		for (var entry : map.entrySet()) {
			if (entry.getValue() == 1)
				max = Math.max(max, entry.getKey());
		}

		return max;
    }
}
