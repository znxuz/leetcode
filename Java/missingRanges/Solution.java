// https://leetcode.com/problems/missing-ranges/

package missingRanges;

import java.util.ArrayList;
import java.util.List;

class Solution {

	public List<String> findMissingRanges(int[] nums, int lower, int upper) {
		List<String> ranges = new ArrayList<>();
		int prev = lower - 1;
		for (int i = 0; i <= nums.length; i++) {
			int current = i < nums.length ? nums[i] : upper + 1;
			if (prev + 1 <= current - 1)
				ranges.add(formatRange(prev + 1, current - 1));
			prev = current;
		}

		return ranges;
    }

    // formats range in the requested format
    private String formatRange(int lower, int upper) {
        if (lower == upper) {
            return String.valueOf(lower);
        }
        return lower + "->" + upper;
    }

}
