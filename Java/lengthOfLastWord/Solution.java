// https://leetcode.com/problems/length-of-last-word/

package lengthOfLastWord;

class Solution {

    public int lengthOfLastWord(String s) {
		int strlen = s.length();
		int wordlen = 0;
		for (int i = strlen - 1; i >= 0; i--) {
			if (s.charAt(i) != ' ')
				wordlen++;
			if (wordlen != 0 && s.charAt(i) == ' ')
				return wordlen;
		}

		return wordlen;
	}

    public int lengthOfLastWordBuiltin(String s) {
		s = s.strip();
		return s.length() - 1 - s.lastIndexOf(' ');
    }
}
