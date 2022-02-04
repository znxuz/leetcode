// https://leetcode.com/problems/number-of-different-integers-in-a-string/

package numberOfDifferentIntegersInString;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int numDifferentIntegers(String word) {
		Set<String> set = new HashSet<>();
		int n = word.length();
		int i = 0;
		int j = 0;
		while (i < n) {
			char c = word.charAt(i);
			if (Character.isDigit(c)) {
				j++;
			} else if (j != 0) {
				set.add(formatStr(word.substring(i - j, i)));
				j = 0;
			}
			i++;
		}
		if (j != 0)
			set.add(formatStr(word.substring(n - j, n)));

		return set.size();
	}

	private String formatStr(String s) {
		s = s.replaceFirst("^0+", "0");
		if (s.charAt(0) != '0' || s.length() == 1)
			return s;
		return s.substring(1);
	}
}
