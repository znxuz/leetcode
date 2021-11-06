// https://leetcode.com/problems/detect-capital/

package detectCapital;

class Solution {

    public boolean detectCapitalUse(String word) {
		if (word == null || word.isBlank())
			return true;

		int len = word.length();
		if (len == 1)
			return true;
		var isCapital = Character.isUpperCase(word.charAt(1));
		if (isCapital) {
			for (int i = 2; i < len; i++) {
				if (Character.isLowerCase(word.charAt(i)))
					return false;
			}
		} else {
			for (int i = 2; i < len; i++) {
				if (Character.isUpperCase(word.charAt(i)))
					return false;
			}
		}

		return !isCapital ?
			true : Character.isUpperCase(word.charAt(0));
	}

    public boolean detectCapitalUseRegex(String word) {
		return word.matches("[a-z]+|[A-Z]+|[A-Z][a-z]+");
	}

}
