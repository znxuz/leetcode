// https://leetcode.com/problems/isomorphic-strings/

package isomorphicStrings;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean isIsomorphic(String s, String t) {
		var dic1 = new int[256];
		var dic2 = new int[256];
		Arrays.fill(dic1, -1);
		Arrays.fill(dic2, -1);

		for (int i = 0; i < s.length(); i++) {
			int c1 = s.charAt(i);
			int c2 = t.charAt(i);
			if (dic1[c1] == -1 && dic2[c2] == -1) {
				dic1[c1] = c2;
				dic2[c2] = c1;
			} else if (dic1[c1] != c2 || dic2[c2] != c1) {
				return false;
			}
		}

		return true;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean isIsomorphicMap(String s, String t) {
		Map<Character, Character> map = new HashMap<>();
		for (int i = 0; i < s.length(); i++) {
			char cs = s.charAt(i);
			char ct = t.charAt(i);
			if (map.containsKey(cs)) {
				if (map.get(cs) != ct)
					return false;
			} else if (map.values().contains(ct)) {
				return false;
			}

			map.put(cs, ct);
		}

		return true;
    }
}
