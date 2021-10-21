// https://leetcode.com/problems/ransom-note/

package ransomNote;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

    public boolean canConstruct(String ransomNote, String magazine) {
		return usingAlphabetArray(ransomNote, magazine);
    }

	// time complexity: O(n + m)
	// space complexity: O(1)
	private boolean usingAlphabetArray(String ransomNote, String magazine) {
		int[] alphabet = new int[26];
		for (char c : ransomNote.toCharArray())
			alphabet[c - 'a']++;
		for (char c : magazine.toCharArray())
				alphabet[c - 'a']--;
		for (int i : alphabet) {
			if (i > 0)
				return false;
		}
		return true;
	}

	// time complexity: O(nlog(n)) + O(n + m)
	// space complexity: O(n + m)
	private boolean usingSortedArray(String ransomNote, String magazine) {
		char[] ransom = ransomNote.toCharArray();
		char[] maga = magazine.toCharArray();
		Arrays.sort(ransom);
		Arrays.sort(maga);

		int i = 0;
		int j = 0;
		while (i < ransom.length && j < maga.length) {
			if (ransom[i] == maga[j]) {
				i++;
				j++;
			} else if (maga[j] < ransom[i]) {
				j++;
			} else {
				return false;
			}
		}

		return i == ransom.length;
	}

	// time complexity: O(n + m) if map operation requires O(1)
	// space complexity: O(1)
	private boolean usingMap(String ransomNote, String magazine) {
		Map<Character, Integer> map = new HashMap<>();
		for (char c : magazine.toCharArray())
			map.put(c, map.getOrDefault(c, 0) + 1);
		for (char c : ransomNote.toCharArray()) {
			int occurrence = map.getOrDefault(c, 0);
			if (occurrence == 0)
				return false;
			map.put(c, --occurrence);
		}

		return true;
	}
}
