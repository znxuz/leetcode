// https://leetcode.com/problems/first-unique-character-in-a-string/

package firstUniqueCharInString;

import java.util.HashMap;
import java.util.Map;

class Solution {

    public int firstUniqChar(String s) {
		return usingArray(s);
    }

	private int usingArray(String s) {
		int[] alphabet = new int[26];
		char[] arr = s.toCharArray();
		for (char c : arr)
			alphabet[c - 'a']++;
		for (int i = 0; i < arr.length; i++) {
			if (alphabet[arr[i] - 'a'] == 1)
				return i;
		}

		return -1;
	}

	private int usingMap(String s) {
		Map<Character, Integer> map = new HashMap<>();
		for (char c : s.toCharArray()) {
			map.put(c, map.getOrDefault(c, 0) + 1);
		}

		for (int i = 0; i < s.length(); i++) {
			if (map.get(s.charAt(i)) == 1)
				return i;
		}

		return -1;
	}

}
