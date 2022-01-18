// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

package replaceAllQuestionMarksToAvoidConsecutiveRepeatingCharacters;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String modifyString(String s) {
		char[] chars = s.toCharArray();
		for (int i = 0; i < chars.length; ++i) {
			if (chars[i] == '?') {
				for (chars[i] = 'a'; chars[i] <= 'c'; chars[i]++) {
					if ((i == 0 || chars[i - 1] != chars[i])
							&& (i == chars.length - 1 || chars[i + 1] != chars[i]))
						break;
				}
			}
		}

		return String.valueOf(chars);
    }
}
