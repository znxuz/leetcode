// https://leetcode.com/problems/single-row-keyboard/

package singleRowKeyboard;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int calculateTime(String keyboard, String word) {
		int[] idx = new int[26];
		for (int i = 0; i < keyboard.length(); ++i)
			idx[keyboard.charAt(i) - 'a'] = i;

		int len = 0;
		int prevIdx = 0;
		for (char c : word.toCharArray()) {
			len += Math.abs(idx[c - 'a'] - prevIdx);
			prevIdx = idx[c - 'a'];
		}

		return len;
	}
}
