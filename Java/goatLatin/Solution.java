// https://leetcode.com/problems/goat-latin/

package goatLatin;

import java.util.Set;

class Solution {

    public String toGoatLatin(String sentence) {
		Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
		String[] words = sentence.split("\\s+");
		var stringBuilder = new StringBuilder();
		int counter = 1;
		for (var word : words) {
			word = (vowels.contains(Character.toLowerCase(word.charAt(0))) ?
				word : word.substring(1) + word.charAt(0)) + "ma";
			stringBuilder.append(" " + word);
			for (int i = 0; i < counter; i++)
				stringBuilder.append("a");
			counter++;
		}

		return stringBuilder.substring(1);
    }
}
