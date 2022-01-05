// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

package decryptStringFromAlphabetToIntegerMapping;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String freqAlphabets(String s) {
		var stringBuilder = new StringBuilder();
		for (int i = s.length() - 1; i >= 0; --i) {
			char c;
			if (s.charAt(i) == '#') {
				int num = s.charAt(--i) - '0' + (s.charAt(--i) - '0') * 10;
				c = (char)(num + 'a' - 1);
			} else {
				c = (char)(s.charAt(i) - '0' + 'a' - 1);
			}
			stringBuilder.append(c);
		}

		return stringBuilder.reverse().toString();
    }
}
