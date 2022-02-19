// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/

package checkIfNumbersAreAscendingInASentence;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean areNumbersAscending(String s) {
		int cur = 0;
		int prev = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (Character.isDigit(s.charAt(i))) {
				cur = cur * 10 + (s.charAt(i) - '0');
			} else if (cur != 0) {
				if (cur <= prev)
					return false;
				prev = cur;
				cur = 0;
			}
		}

		return cur == 0 || cur > prev;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean areNumbersAscendingPointers(String s) {
		int i = 0;
		int prev = 0;
		while (i < s.length()) {
			if (!Character.isDigit(s.charAt(i))) {
				i++;
				continue;
			}
			int j = i;
			while (j < s.length() && s.charAt(j) != ' ')
				j++;
			int num = Integer.parseInt(s.substring(i, j));
			if (num <= prev)
				return false;
			prev = num;
			i = j;
		}
		return true;
    }
}
