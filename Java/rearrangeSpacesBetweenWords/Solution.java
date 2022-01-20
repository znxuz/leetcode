// https://leetcode.com/problems/rearrange-spaces-between-words/

package rearrangeSpacesBetweenWords;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String reorderSpaces(String text) {
		int spaces = 0;
		int words = 0;
		char[] chars = text.toCharArray();
		for (int i = 0; i < chars.length; ++i) {
			if (chars[i] == ' ')
				spaces++;
			else if (i == 0 || chars[i - 1] == ' ')
				words++;
		}

		int avg = words == 1 ? 0 : spaces / (words - 1);
		int rest = words == 1 ? spaces : spaces % (words - 1);
		var stringBuilder = new StringBuilder();
		for (int i = 0; i < chars.length; ++i) {
			if (chars[i] == ' ') {
				if (i != 0 && chars[i - 1] != ' ' && words > 1) {
					words--;
					for (int j = 0; j < avg; ++j)
						stringBuilder.append(' ');
				}
			} else {
				stringBuilder.append(chars[i]);
			}
		}

		while (rest-- > 0)
			stringBuilder.append(' ');

		return stringBuilder.toString();
    }
}
