// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

package findNUniqueIntegersSumUpToZero;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] sumZero(int n) {
		int[] res = new int[n];

		res[res.length - 1] = -(n * (n - 1) / 2);
		for (int i = 0; i < res.length - 1; ++i)
			res[i] = --n;

		return res;
    }
}
