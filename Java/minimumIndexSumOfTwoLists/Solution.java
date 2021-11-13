// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

package minimumIndexSumOfTwoLists;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

    public String[] findRestaurant(String[] list1, String[] list2) {
		Map<String, Integer> map = new HashMap<>();
		for (int i = 0; i < list1.length; i++) {
			map.put(list1[i], i);
		}

		List<String> ret = new ArrayList<>();
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < list2.length; i++) {
			var current = list2[i];
			if (map.containsKey(current)) {
				int sum = map.get(current) + i;
				if (sum <= min) {
					if (sum < min) {
						min = sum;
						ret.clear();
					}
					ret.add(current);
				}
			}
		}

		return ret.toArray(new String[ret.size()]);
    }

}
