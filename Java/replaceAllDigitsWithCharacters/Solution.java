// https://leetcode.com/problems/replace-all-digits-with-characters/

package replaceAllDigitsWithCharacters;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String replaceDigits(String s) {
		char[] chars = s.toCharArray();
		for (int i = 1; i < chars.length; i += 2) {
			chars[i] = (char)(chars[i - 1] + chars[i] - '0');
		}

		return String.valueOf(chars);
    }
}
