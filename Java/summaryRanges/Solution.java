// https://leetcode.com/problems/summary-ranges/

package summaryRanges;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<String> summaryRanges(int[] nums) {
		List<String> list = new ArrayList<>();
		return summaryRangesRec(nums, 0, list);
    }

	// time complexity: O(n)
	// space complexity: O(n)
	private List<String> summaryRangesRec(int[] nums, int index, List<String> list) {
		if (index >= nums.length)
			return list;

		int counter = 0;
		while (index + counter < nums.length
				&& nums[index + counter] == nums[index] + counter)
			counter++;
		list.add(getRange(nums[index], nums[index + counter - 1]));

		if (index + counter < nums.length)
			summaryRangesRec(nums, index + counter, list);

		return list;
	}

	private String getRange(int from, int to) {
		if (from == to)
			return Integer.toString(from);
		return String.format("%d->%d", from, to);
	}

}
