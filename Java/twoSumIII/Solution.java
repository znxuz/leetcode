// https://leetcode.com/problems/two-sum-iii-data-structure-design/

package twoSumIII;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class TwoSum {

	private final List<Integer> distinct = new ArrayList<>();
	private final Map<Integer, Integer> numMap = new HashMap<>();

    public void add(int number) {
		int occurance = numMap.getOrDefault(number, 0);
		if (occurance == 0) {
			distinct.add(number);
		}
		numMap.put(number, occurance + 1);
	}
    
    public boolean find(int value) {
		for (int i : distinct) {
			int complement = value - i;
			if ((i == complement && numMap.get(i) > 1)
					|| (i != complement && numMap.containsKey(complement)))
				return true;
		}

		return false;
    }

}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
