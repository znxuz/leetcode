// https://leetcode.com/problems/uncommon-words-from-two-sentences/

package uncommonWordsFromTwoSentences;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n + m): n, m lengths of s1, s2
	// space complexity: O(n)
    public String[] uncommonFromSentences(String s1, String s2) {
		Map<String, Integer> map = new HashMap<>();
		for (var word : (s1 + " " + s2).split("\\s"))
			map.put(word, map.getOrDefault(word, 0) + 1);

		return map.entrySet().stream()
			.filter(e -> e.getValue() == 1)
			.map(e -> e .getKey())
			.toArray(String[]::new);
	}

}
