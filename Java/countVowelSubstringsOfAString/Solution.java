// https://leetcode.com/problems/count-vowel-substrings-of-a-string/

package countVowelSubstringsOfAString;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n^2)
	// space complexity: O(n)
    public int countVowelSubstringsMap(String word) {
		Map<Character, Boolean> map = new HashMap<>();
		map.putAll(Map.of('a', false, 'e', false, 'i', false, 'o', false, 'u', false));

		int cnt = 0;
		for (int i = 0; i < word.length(); ++i) {
			if (!map.containsKey(word.charAt(i)))
				continue;
			map.put(word.charAt(i), true);
			for (int j = i + 1; j < word.length() && map.containsKey(word.charAt(j)); ++j) {
				map.put(word.charAt(j), true);
				if (!map.values().contains(false))
					cnt++;
			}
			for (var k : map.keySet())
				map.put(k, false);
		}

		return cnt;
    }
}
