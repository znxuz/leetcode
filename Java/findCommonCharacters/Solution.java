// https://leetcode.com/problems/find-common-characters/

package findCommonCharacters;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n * m): n - length of the array, m - length of each string
	// space complexity: O(n)
    public List<String> commonChars(String[] words) {
		if (words == null || words.length == 0)
			return null;

		int[] common = new int[26];
		for (char c : words[0].toCharArray())
			common[c - 'a']++;
		for (int i = 1; i < words.length; ++i) {
			int[] chars = new int[26];
			for (char c : words[i].toCharArray())
				chars[c - 'a']++;
			for (int j = 0; j < common.length; ++j)
				common[j] = Math.min(common[j], chars[j]);
		}

		List<String> list = new ArrayList<>();
		for (int i = 0; i < common.length; ++i) {
			while (common[i]-- > 0)
				list.add(String.valueOf((char)(i + 'a')));
		}

		return list;
    }
}
