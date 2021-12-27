// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

package numberOfEquivalentDominoPairs;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// gauss formula / combinatorics
	// time complexity: O(n)
	// space complexity :O(n)
    public int numEquivDominoPairs(int[][] dominoes) {
		Map<Integer, Integer> map = new HashMap<>();
		for (var pair : dominoes) {
			int min = Math.min(pair[0], pair[1]);
			int max = Math.max(pair[0], pair[1]);
			int sum = min * 10 + max;
			map.put(sum, map.getOrDefault(sum, 0) + 1);
		}

		int res = 0;
		for (int sum : map.values())
			res += sum * (sum - 1) / 2;

		return res;
    }

}
