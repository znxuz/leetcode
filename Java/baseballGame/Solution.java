// https://leetcode.com/problems/baseball-game/

package baseballGame;

import java.util.LinkedList;
import java.util.List;

class Solution {

	// time complexity: O(n * m), m - length of each operation
	// space complexity: O(n)
    public int calPoints(String[] ops) {
		List<Integer> stack = new LinkedList<>();
		for (String op : ops) {
			if (isNumbers(op)) {
				stack.add(Integer.parseInt(op));
			} else if ("+".equals(op)) {
				stack.add(stack.get(stack.size() - 1) + stack.get(stack.size() - 2));
			} else if ("D".equals(op)) {
				stack.add(2 * stack.get(stack.size() - 1));
			} else if ("C".equals(op)) {
				stack.remove(stack.size() - 1);
			}
		}

		return stack.stream().reduce(0, Integer::sum);
    }

	private boolean isNumbers(String s) {
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 && s.charAt(i) == '-')
				continue;
			if (!Character.isDigit(s.charAt(i)))
				return false;
		}

		return true;
	}

}
