// https://leetcode.com/problems/valid-word-abbreviation/

package validWordAbbreviation;

class Solution {

    public boolean validWordAbbreviation(String word, String abbr) {
		int wordLen = word.length();
		int abbrLen = abbr.length();
		int i = 0;
		int j = 0;
		while (i < wordLen && j < abbrLen) {
			if (Character.isDigit(abbr.charAt(j))) {
				int len = Character.getNumericValue(abbr.charAt(j));
				if (len == 0)
					return false;
				while (j + 1 < abbrLen && Character.isDigit(abbr.charAt(j + 1))) {
					len = len * 10 + Character.getNumericValue(abbr.charAt(++j));
				}
				i += len;
				j++;
			} else if (word.charAt(i) == abbr.charAt(j)) {
				i++;
				j++;
			} else {
				return false;
			}
		}

		return i == wordLen && j == abbrLen;
    }

    public boolean validWordAbbreviationRegex(String word, String abbr) {
		return word.matches(abbr.replaceAll("[1-9]\\d*", ".{$0}"));
	}

}
