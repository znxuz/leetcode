// https://leetcode.com/problems/remove-outermost-parentheses/

package removeOutmostParentheses;

import java.util.LinkedList;
import java.util.Queue;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String removeOuterParentheses(String s) {
		Queue<Character> q = new LinkedList<>();
		var stringBuilder = new StringBuilder();
		for (char c : s.toCharArray()) {
			if (c == '(') {
				q.offer(c);
				if (q.size() > 1)
					stringBuilder.append(c);
			} else {
				q.poll();
				if (!q.isEmpty())
					stringBuilder.append(c);
			}
		}

		return stringBuilder.toString();
    }
}
