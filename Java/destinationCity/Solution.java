// https://leetcode.com/problems/destination-city/

package destinationCity;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {

    public String destCity(List<List<String>> paths) {
		Set<String> set = new HashSet<>();
		for (var p : paths)
			set.add(p.get(1));
		for (var p : paths)
			set.remove(p.get(0));
		return set.iterator().next();
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public String destCityMap(List<List<String>> paths) {
		Map<String, Integer> map = new HashMap<>();
		for (var p : paths) {
			map.put(p.get(0), map.getOrDefault(p.get(0), 0) - 1);
			map.put(p.get(1), map.getOrDefault(p.get(1), 0) + 1);
		}
		return map.entrySet().stream().filter(e -> e.getValue() == 1).findFirst().get().getKey();
    }
}
