// https://leetcode.com/problems/most-common-word/

package mostCommonWord;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String mostCommonWord(String paragraph, String[] banned) {
		Set<String> bannedSet = new HashSet<>(Set.of(banned));
		Map<String, Integer> map = new HashMap<>();
		String[] words = paragraph.toLowerCase().split("[\\s!?',;.]+");

		for (var word : words) {
			if (!bannedSet.contains(word))
				map.put(word, map.getOrDefault(word, 0) + 1);
		}

		return Collections.max(map.entrySet(), Map.Entry.comparingByValue()).getKey();
    }

}
