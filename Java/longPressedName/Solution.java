// https://leetcode.com/problems/long-pressed-name/

package longPressedName;

class Solution {

	// time complexity: O(n + m): n, m lengths of both strings
	// space complexity: O(1)
    public boolean isLongPressedName(String name, String typed) {
		int i = 0;
		int j = 0;
		char prev = 0;
		while (i < name.length() && j < typed.length()) {
			if (name.charAt(i) == typed.charAt(j)) {
				prev = name.charAt(i);
				i++;
				j++;
			} else if (typed.charAt(j) == prev) {
				j++;
			} else {
				return false;
			}
		}

		if (i < name.length())
			return false;
		while (j < typed.length())
			if (typed.charAt(j++) != name.charAt(name.length() - 1))
				return false;

		return true;
    }
}
