// https://leetcode.com/problems/verifying-an-alien-dictionary/

package verifyingAnAlienDictionary;

class Solution {

	// time complexity: O(n * m): n - array len, m - strlen
	// space complexity: O(1)
    public boolean isAlienSorted(String[] words, String order) {
		int[] map = new int[26];
		for (int i = 0; i < order.length(); ++i)
			map[order.charAt(i) - 'a'] = i;

		for (int i = 0; i < words.length - 1; ++i) {
			if (compare(words[i + 1], words[i], map) < 0)
				return false;
		}

		return true;
    }

	private int compare(String s, String t, int[] map) {
		int i = 0, j = 0;
		while (i < s.length() || j < t.length()) {
			int diff = i < s.length() && j < t.length() ?
				map[s.charAt(i) - 'a'] - map[t.charAt(j) - 'a'] : j == t.length() ? 1 : -1;
			if (diff != 0)
				return diff;
			i++;
			j++;
		}

		return 0;
	}

}
