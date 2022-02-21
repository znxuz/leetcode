// https://leetcode.com/problems/find-target-indices-after-sorting-array/

package findTargetIndicesAfterSortingArray;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time: O(n)
	// space: O(1)
    public List<Integer> targetIndices(int[] nums, int target) {
		int[] cnts = new int[101];
		for (int n : nums)
			cnts[n]++;

		int idx = 0;
		for (int i = 0; i < target; ++i)
			idx += cnts[i];
		List<Integer> ret = new ArrayList<>();
		while (cnts[target]-- > 0)
			ret.add(idx++);

		return ret;
    }
}
