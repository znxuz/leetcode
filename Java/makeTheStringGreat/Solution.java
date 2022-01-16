// https://leetcode.com/problems/make-the-string-great/

package makeTheStringGreat;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String makeGood(String s) {
		Deque<Character> deque = new ArrayDeque<>();
		for (var c : s.toCharArray()) {
			if (deque.isEmpty() || Math.abs(c - deque.peekLast()) != 32)
				deque.offerLast(c);
			else
				deque.pollLast();
		}

		char[] arr = new char[deque.size()];
		for (int i = 0; i < arr.length; ++i)
			arr[i] = deque.pollFirst();

		return String.valueOf(arr);
    }
}
