// https://leetcode.com/problems/backspace-string-compare/

package backspaceStringCompare;

import java.util.Stack;

class Solution {

	// backwards iterating the strings so that we know
	// 	how many chars we need to skip
	// time complexity: O(n)
	// space complexity: O(1)
    public boolean backspaceCompare(String s, String t) {
		int i = s.length() - 1;
		int j = t.length() - 1;
		int skipS = 0;
		int skipT = 0;
		while (i >= 0 || j >= 0) {
			while (i >= 0) {
				if (s.charAt(i) == '#') {
					skipS++;
					i--;
				} else if (skipS > 0) {
					skipS--;
					i--;
				} else {
					break;
				}
			}
			while (j >= 0) {
				if (t.charAt(j) == '#') {
					skipT++;
					j--;
				} else if (skipT > 0) {
					skipT--;
					j--;
				} else {
					break;
				}
			}
			if (i >= 0 && j >= 0 && s.charAt(i) != t.charAt(j))
				return false;
			if ((i >= 0) != (j >= 0))
				return false;
			i--;
			j--;
		}

		return true;
	}

	// time complexity: O(n + m): n, m for lengths of s, t
	// spcae complexity: O(n + m): n, m for lengths of s, t
    public boolean backspaceCompareStack(String s, String t) {
		return build(s).equals(build(t));
    }

	private String build(String s) {
		Stack<Character> stack = new Stack<>();
		for (char c : s.toCharArray()) {
			if (c != '#')
				stack.push(c);
			else if (!stack.isEmpty())
				stack.pop();
		}

		return stack.toString();
	}
}
