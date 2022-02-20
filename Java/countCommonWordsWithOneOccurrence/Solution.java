// https://leetcode.com/problems/count-common-words-with-one-occurrence/

package countCommonWordsWithOneOccurrence;

import java.util.HashMap;
import java.util.Map;

class Solution {

    public int countWords(String[] words1, String[] words2) {
		Map<String, Integer> map = new HashMap<>();
		for (var s : words1) {
			map.put(s, map.getOrDefault(s, 0) + 1);
		}
		for (var s : words2) {
			if (map.containsKey(s) && map.get(s) == 1)
				map.put(s, 0);
			else
				map.remove(s);
		}

		int cnt = 0;
		for (var entry : map.entrySet())
			if (entry.getValue() == 0)
				cnt++;
		return cnt;
    }
}
