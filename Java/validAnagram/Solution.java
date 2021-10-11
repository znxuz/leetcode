// https://leetcode.com/problems/valid-anagram/

package validAnagram;

import java.util.Arrays;

class Solution {

	public boolean isAnagram(String s, String t) {
		if (s.length() != t.length())
			return false;

		char[] sChar = s.toCharArray();
		char[] tChar = t.toCharArray();

		Arrays.sort(sChar);
		Arrays.sort(tChar);

		return Arrays.equals(sChar, tChar);
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean isAnagramHashTable(String s, String t) {
		int sLen = s.length();
		int tLen = t.length();
		if (sLen != tLen)
			return false;

		char[] map1 = new char[26];

		for (int i = 0; i < sLen; i++) {
			int indexS = s.charAt(i) - 'a';
			int indexT = t.charAt(i) - 'a';
			map1[indexS] = ++map1[indexS];
			map1[indexT] = --map1[indexT];
		}

		for (int i = 0; i < map1.length; i++) {
			if (map1[i] != 0)
				return false;
		}

		return true;
    }
}
