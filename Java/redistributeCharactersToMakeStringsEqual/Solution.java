// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

package redistributeCharactersToMakeStringsEqual;

class Solution {

	// time complexity: O(n * m) : m for length of each word
	// space complexity: O(1)
    public boolean makeEqual(String[] words) {
		int[] cnts = new int[26];
		for (var w : words) {
			for (var c : w.toCharArray())
				cnts[c - 'a']++;
		}
		for (int c : cnts) {
			if (c % words.length != 0)
				return false;
		}
		return true;
    }
}
