// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

package checkIfTwoStringArraysAreEquivalent;

import java.util.ArrayDeque;
import java.util.Queue;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
		int i1 = 0, i2 = 0, c1 = 0, c2 = 0;
		while (i1 < word1.length && i2 < word2.length) {
			if (word1[i1].charAt(c1++) != word2[i2].charAt(c2++))
				return false;
			if (c1 == word1[i1].length()) {
				c1 = 0;
				i1++;
			}
			if (c2 == word2[i2].length()) {
				c2 = 0;
				i2++;
			}
		}

		return i1 == word1.length && i2 == word2.length;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean arrayStringsAreEqualQueue(String[] word1, String[] word2) {
		Queue<Character> q = new ArrayDeque<>();
		for (var w : word1) {
			for (char c : w.toCharArray())
				q.offer(c);
		}
		for (var w : word2) {
			for (char c : w.toCharArray()) {
				if (q.isEmpty() || q.poll() != c)
					return false;
			}
		}

		return q.isEmpty();
	}

	// time complexity: O(n)
	// spce complexity: O(n)
    public boolean arrayStringsAreEqualLinear(String[] word1, String[] word2) {
		var stringBuilder = new StringBuilder();
		for (var w : word1)
			stringBuilder.append(w);
		var s1 = stringBuilder.toString();
		stringBuilder.setLength(0);
		for (var w : word2)
			stringBuilder.append(w);
		return s1.equals(stringBuilder.toString());
    }

    public boolean arrayStringsAreEqualBuiltIn(String[] word1, String[] word2) {
		return String.join("", word1).equals(String.join("", word2));
	}

}
