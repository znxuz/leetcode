// https://leetcode.com/problems/count-items-matching-a-rule/

package countItemsMatchingARule;

import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
		int filter = ruleKey.equals("type") ? 0 : ruleKey.equals("color") ? 1 : 2;
		int cnt = 0;
		for (var list : items) {
			if (list.get(filter).equals(ruleValue))
				cnt++;
		}

		return cnt;
    }
}
