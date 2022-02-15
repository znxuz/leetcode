// https://leetcode.com/problems/reverse-prefix-of-word/

package reversePrefixOfWord;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String reversePrefix(String word, char ch) {
		int i = 0;
		while (i < word.length() && word.charAt(i) != ch)
			i++;

		if (i == 0 || i == word.length())
			return word;
		return new StringBuilder(word.substring(0, i + 1)).reverse().toString() + word.substring(i + 1);
    }
}
