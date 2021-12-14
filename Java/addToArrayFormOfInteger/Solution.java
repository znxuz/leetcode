// https://leetcode.com/problems/add-to-array-form-of-integer/

package addToArrayFormOfInteger;

import java.util.LinkedList;
import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public List<Integer> addToArrayForm(int[] num, int k) {
		LinkedList<Integer> linked = new LinkedList<>();

		int carry = 0;
		for (int i = num.length - 1; i >= 0 || k > 0; --i) {
			int cur = (i >= 0 ? num[i] : 0) + k % 10 + carry;
			carry = cur / 10;
			cur %= 10;
			k /= 10;
			linked.addFirst(cur);
		}
		if (carry == 1)
			linked.addFirst(carry);

		return linked;
    }
}
