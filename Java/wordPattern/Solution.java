// https://leetcode.com/problems/word-pattern/

package wordPattern;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean wordPatternMap(String pattern, String s) {
		Map<Character, String> map = new HashMap<>();
		String[] array = s.split(" ");

		int i = 0;
		while (i < pattern.length() && i < array.length) {
			char c = pattern.charAt(i);
			if (map.containsKey(c)) {
				if (!map.get(c).equals(array[i]))
				return false;
			} else if (map.containsValue(array[i]))
				return false;
			map.put(c, array[i]);
			i++;
		}

		return i == pattern.length() && i == array.length;
    }
}
