// https://leetcode.com/problems/positions-of-large-groups/

package positionOfLargeGroups;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<List<Integer>> largeGroupPositions(String s) {
		List<List<Integer>> groups = new ArrayList<>();
		for (int i = 0; i < s.length() - 1; i++) {
			int end = i;
			while (end + 1 < s.length() && s.charAt(end + 1) == s.charAt(i))
				end++;
			if (end - i >= 2)
				groups.add(List.of(i, end));
			i = end;
		}

		return groups;
    }
}
