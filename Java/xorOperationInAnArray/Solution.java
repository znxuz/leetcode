// https://leetcode.com/problems/xor-operation-in-an-array/

package xorOperationInAnArray;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int xorOperationLinear(int n, int start) {
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int cur = start + 2 * i;
			if (i == 0)
				res = cur;
			else
				res ^= cur;
		}

		return res;
    }
}
