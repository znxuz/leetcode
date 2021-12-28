// https://leetcode.com/problems/maximum-number-of-words-you-can-type/

package maximumNumberOfWordsYouCanType;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int canBeTypedWords(String text, String brokenLetters) {
		boolean[] broken = new boolean[26];
		for (char c : brokenLetters.toCharArray())
			broken[c - 'a'] = true;
		boolean canType = true;
		int ctr = 0;
		for (char c : text.toCharArray()) {
			if (c == ' ') {
				ctr += canType ? 1 : 0;
				canType = true;
			} else if (broken[c - 'a'])
				canType = false;
		}
		ctr += canType ? 1 : 0;

		return ctr;
	}

	// time complexity: O(n + m)
	// space complexity: O(n)
    public int canBeTypedWordsSet(String text, String brokenLetters) {
		Set<Character> broken = new HashSet<>();
		for (char c : brokenLetters.toCharArray()) {
			broken.add(c);
		}

		int ctr = 0;
		for (var word : text.split("\\s+")) {
			boolean flag = true;
			for (int i = 0; i < word.length() && flag; ++i) {
				if (broken.contains(word.charAt(i)))
					flag = false;
			}
			ctr += flag ? 1 : 0;
		}

		return ctr;
    }
}
