// https://leetcode.com/problems/valid-parentheses/

package validParenthesis;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class Solution {

	private static final Map<Character, Character> pairs = new HashMap<>();
	static {
		pairs.put(')', '(');
		pairs.put(']', '[');
		pairs.put('}', '{');
	}

	public boolean isValidStack(String s) {
		Stack<Character> stack = new Stack<>();
		for (int i = 0; i < s.length(); i++) {
			char current = s.charAt(i);
			if (pairs.containsKey(current)) {
				char top = stack.isEmpty() ? ' ' : stack.peek();
				if (pairs.get(current) == top)
					stack.pop();
				else
					return false;
			} else {
				stack.push(current);
			}
		}

		return stack.isEmpty();
	}

	public boolean isValid(String s) {
		int length = 0;
		do {
			length = s.length();
			s = s.replace("()", "").replace("{}", "").replace("[]", "");
		} while (length != s.length());
		return s.isBlank();
	}
}
