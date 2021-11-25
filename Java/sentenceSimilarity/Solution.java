// https://leetcode.com/problems/sentence-similarity/

package sentenceSimilarity;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {

    public boolean areSentencesSimilar(String[] sentence1, String[] sentence2,
			List<List<String>> pairs) {
		if (sentence1.length != sentence2.length)
			return false;

		Map<String, Set<String>> map = new HashMap<>();
		for (var pair : pairs) {
			map.putIfAbsent(pair.get(0), new HashSet<>());
			map.putIfAbsent(pair.get(1), new HashSet<>());
			map.get(pair.get(0)).add(pair.get(1));
			map.get(pair.get(1)).add(pair.get(0));
		}

		for (int i = 0; i < sentence1.length; i++) {
			if (sentence1[i].equals(sentence2[i]))
				continue;
			if (!map.containsKey(sentence1[i]) || !map.get(sentence1[i]).contains(sentence2[i]))
				return false;
		}

		return true;
    }
}
