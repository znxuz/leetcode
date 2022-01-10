// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

package makeTwoArraysEqualByReversingSubarrays;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean canBeEqualCountingSort(int[] target, int[] arr) {
		if (target.length != arr.length)
			return false;

		int[] ctrs = new int[1001];
		for (int i = 0; i < target.length; ++i) {
			ctrs[target[i]]++;
			ctrs[arr[i]]--;
		}
		for (int n : ctrs)
			if (n != 0)
				return false;

		return true;
    }
}
