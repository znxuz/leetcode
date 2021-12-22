// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

package findWordsThatCanBeFormedByChars;

import java.util.Arrays;

class Solution {

	// time complexity: O(n * m): n, m for length of the array and length of each str
	// space complexity: O(n) for arrays copying
    public int countCharacters(String[] words, String chars) {
		char[] alph = new char[26];
		for (char c : chars.toCharArray())
			alph[c - 'a']++;
		int len = 0;

		for (var w : words) {
			if (w.length() > chars.length())
				continue;
			var tmp = Arrays.copyOf(alph, alph.length);
			int ctr = 0;
			for (char c : w.toCharArray()) {
				if (tmp[c - 'a']-- > 0)
					ctr++;
			}
			if (ctr == w.length())
				len += w.length();
		}

		return len;
    }
}
