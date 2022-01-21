// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

package largestSubstringBetweenTwoEqualCharacters;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxLengthBetweenEqualCharacters(String s) {
		int[] idx = new int[26];
		int max = -1;

		for (int i = 0; i < s.length(); ++i) {
			int cur = s.charAt(i) - 'a';
			if (idx[cur] == 0)
				idx[cur] = i + 1;
			else
				max = Math.max(max, i - idx[cur]);
		}

		return max;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxLengthBetweenEqualCharactersMap(String s) {
		Map<Character, int[]> map = new HashMap<>();
		for (int i = 0; i < s.length(); ++i) {
			int[] anchors = map.get(s.charAt(i));
			if (anchors == null) {
				anchors = new int[]{i, -1};
				map.put(s.charAt(i), anchors);
			} else {
				anchors[1] = i;
			}
		}

		int max = -1;
		for (var entry : map.entrySet()) {
			if (entry.getValue()[1] != -1) {
				int[] anchors = entry.getValue();
				max = Math.max(max, anchors[1] - anchors[0] - 1);
			}
		}

		return max;
    }
}
