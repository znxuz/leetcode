// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

package checkIfAWordOccursAsAPrefixOfAnyWordInASentence;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int isPrefixOfWord(String sentence, String prefix) {
		int i = 0;
		int j = 0;
		int ctr = 0;
		boolean check = true;
		while (i < sentence.length()) {
			if (sentence.charAt(i) == ' ') {
				ctr++;
				j = 0;
				check = true;
			} else if (check && sentence.charAt(i) == prefix.charAt(j)) {
				j++;
			} else {
				j = 0;
				check = false;
			}
			if (j == prefix.length())
				return ctr + 1;
			i++;
		}

		return -1;
	}

	// time complexity: O(n^2)
	// space complexity: O(n)
    public int isPrefixOfWordBuiltInMethods(String sentence, String searchWord) {
		String[] words = sentence.split("\\s");
		for (int i = 0; i < words.length; ++i) {
			if (words[i].startsWith(searchWord))
				return i + 1;
		}

		return -1;
    }
}
