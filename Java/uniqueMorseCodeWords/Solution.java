// https://leetcode.com/problems/unique-morse-code-words/

package uniqueMorseCodeWords;

import java.util.HashSet;
import java.util.Set;

class Solution {

	private final String[] morse = {".-", "-...", "-.-.", "-..",
		".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
		"--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
		"..-", "...-", ".--", "-..-", "-.--", "--.."};

    public int uniqueMorseRepresentations(String[] words) {
		Set<String> set = new HashSet<>();
		StringBuilder stringBuilder = new StringBuilder();
		for (var word : words) {
			for (char c : word.toCharArray()) {
				stringBuilder.append(morse[c - 'a']);
			}
			set.add(stringBuilder.toString());
			stringBuilder.setLength(0);
		}

		return set.size();
    }
}
