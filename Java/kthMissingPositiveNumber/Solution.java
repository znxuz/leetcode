// https://leetcode.com/problems/kth-missing-positive-number/

package kthMissingPositiveNumber;

class Solution {

    public int findKthPositive(int[] arr, int k) {
		// TODO binary search
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int findKthPositiveLinear(int[] arr, int k) {
		if (k < arr[0])
			return k;
		int missing = 0;
		int prev = 0;
		int i = 0;
		while (i < arr.length && missing < k) {
			int diff = arr[i] - prev - 1;
			if (missing + diff >= k)
				break;
			missing += diff;
			prev = arr[i];
			i++;
		}

		return arr[i - 1] + k - missing;
    }
}
