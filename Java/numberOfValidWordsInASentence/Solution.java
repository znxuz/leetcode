// https://leetcode.com/problems/number-of-valid-words-in-a-sentence/

package numberOfValidWordsInASentence;

import java.util.regex.Pattern;

class Solution {

    public int countValidWords(String s) {
		Pattern p = Pattern.compile("(([a-zA-Z]*)|([a-zA-Z]+-[a-zA-Z]+))[,.!]?");
		int cnt = 0;
		for (var w : s.strip().split("\\s+"))
			cnt += (p.matcher(w).matches()) ? 1 : 0;

		return cnt;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int countValidWordsScan(String s) {
		int cnt = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == ' ')
				continue;

			int j = i;
			while (j < s.length() && s.charAt(j) != ' ')
				j++;
			cnt += (valid(s.substring(i, j))) ? 1 : 0;
			i = j;
		}

		return cnt;
    }

	private boolean valid(String w) {
		int hyphen = 0;
		int punct = 0;
		for (int i = 0; i < w.length(); ++i) {
			int c = w.charAt(i);
			if (Character.isDigit(c))
				return false;
			if (c == '-'
					&& (hyphen++ > 0 || i == 0 || i == w.length() - 1
						|| !Character.isLetter(w.charAt(i - 1)) || !Character.isLetter(w.charAt(i + 1))))
				return false;
			if ((c == '!' || c == ',' || c == '.')
					&& (punct++ > 0 || i != w.length() - 1))
				return false;
		}

		return true;
	}
}
