// https://leetcode.com/problems/find-lucky-integer-in-an-array/

package findLuckyNumberInAnArray;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int findLucky(int[] arr) {
		int[] ctrs = new int[501];
		for (int n : arr)
			ctrs[n]++;

		int largest = -1;
		for (int i = 0; i < ctrs.length; ++i) {
			if (ctrs[i] != 0 && i == ctrs[i])
				largest = i;
		}

		return largest;
    }
}
