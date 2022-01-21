// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

package maximumNestingDepthOfTheParentheses;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxDepth(String s) {
		int max = 0;
		int cnt = 0;
		for (char c : s.toCharArray()) {
			if (c == '(') {
				cnt++;
				max = Math.max(max, cnt);
			} else if (c == ')')
				cnt--;
		}

		return max;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int maxDepthStack(String s) {
		Deque<Character> stack = new ArrayDeque<>();
		int cnt = 0;
		for (char c : s.toCharArray()) {
			if (c == '(') {
				stack.offerLast(c);
				cnt = Math.max(cnt, stack.size());
			}
			else if (c == ')')
				stack.pollLast();
		}

		return cnt;
    }
}
