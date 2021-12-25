// https://leetcode.com/problems/duplicate-zeros/

package duplicateZeros;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public void duplicateZeros(int[] arr) {
		int ctr = 0;
		for (int n : arr) {
			if (n == 0)
				ctr++;
		}

		int last = arr.length - 1 + ctr;
		for (int i = arr.length - 1; i >= 0; --i) {
			if (arr[i] == 0) {
				for (int j = 0; j < 2; ++j) {
					if (last < arr.length)
						arr[last] = 0;
					last--;
				}
			} else {
				if (last < arr.length)
					arr[last] = arr[i];
				last--;
			}
		}
	}
}
