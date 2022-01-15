// https://leetcode.com/problems/shuffle-string/

package shuffleString;

import java.util.Map;
import java.util.TreeMap;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String restoreString(String s, int[] indices) {
		char[] chars = s.toCharArray();
		for (int i = 0; i < chars.length; ++i) {
			while (i != indices[i]) {
				swapChar(chars, i, indices[i]);
				swapIdx(indices, i, indices[i]);
			}
		}

		return String.valueOf(chars);
	}

	private void swapChar(char[] chars, int i1, int i2) {
		char tmp = chars[i1];
		chars[i1] = chars[i2];
		chars[i2] = tmp;
	}

	private void swapIdx(int[] indices, int i1, int i2) {
		int tmp = indices[i1];
		indices[i1] = indices[i2];
		indices[i2] = tmp;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public String restoreStringArray(String s, int[] indices) {
		char[] tmp = new char[indices.length];
		for (int i = 0; i < indices.length; ++i) {
			tmp[indices[i]] = s.charAt(i);
		}

		return String.valueOf(tmp);
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public String restoreStringTreeMap(String s, int[] indices) {
		Map<Integer, Character> treemap = new TreeMap<>();
		for (int i = 0; i < indices.length; ++i) {
			treemap.put(indices[i], s.charAt(i));
		}

		var stringBuilder = new StringBuilder();
		for (var entry : treemap.entrySet()) {
			stringBuilder.append(entry.getValue());
		}

		return stringBuilder.toString();
    }
}
