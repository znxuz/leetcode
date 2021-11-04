// https://leetcode.com/problems/keyboard-row/

package keyboardRow;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

	public int[] getAlphaMap() {
		String[] rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
		int[] alpha = new int[26];
		for (int i = 0; i < alpha.length; i++) {
			char current = (char)(i + 'a');
			for (int j = 0; j < rows.length; j++) {
				for (int k = 0; k < rows[j].length(); k++) {
					if (rows[j].charAt(k) == current)
						alpha[i] = j;
				}
			}
		}

		return alpha;
	}

	// words.length = n, word[i].length() = m
	// time complexity: O(1) + O(n * m)
	// space complexity: O(n)
    public String[] findWords(String[] words) {
		List<String> list = new ArrayList<>();
		int[] alpha = getAlphaMap();
		for (int i = 0; i < words.length; i++) {
			String s = words[i].toLowerCase();
			boolean isSameRow = true;
			int row = alpha[s.charAt(0) - 'a'];
			for (int k = 1; k < s.length(); k++) {
				if (alpha[s.charAt(k) - 'a'] != row) {
					isSameRow = false;
					break;
				}
			}
			if (isSameRow)
				list.add(words[i]);
		}

		return list.toArray(new String[0]);
    }

    public String[] findWordsStream(String[] words) {
		return Arrays.stream(words)
			.filter(s -> s.toLowerCase().matches("[qwertyuiop]+|[asdfghjkl]+|[zxcvbnm]+"))
			.toArray(String[]::new);
	}
}
