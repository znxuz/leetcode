// https://leetcode.com/problems/buddy-strings/

package buddyStrings;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// time compleixty: O(n)
	// space complexity; O(1)
    public boolean buddyStrings(String s, String goal) {
		int length = s.length();
		if (length != goal.length())
			return false;

		int i = 0;
		while (i < length && s.charAt(i) == goal.charAt(i))
			i++;
		int j = i + 1;
		while (j < length && s.charAt(j) == goal.charAt(j))
			j++;

		if (i == length)
			// return s.chars().distinct().count() != length;
			return !isDistinct(s);
		if (j == length)
			return false;
		if (s.charAt(i) != goal.charAt(j) || s.charAt(j) != goal.charAt(i))
			return false;
		while (++j < length) {
			if (s.charAt(j) != goal.charAt(j))
				return false;
		}

		return true;
    }

	private boolean isDistinct(String s) {
		Set<Character> set = new HashSet<>();
		for (char c : s.toCharArray()) {
			if (!set.add(c))
				return false;
		}

		return true;
	}

}
