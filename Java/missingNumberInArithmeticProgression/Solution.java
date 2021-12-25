// https://leetcode.com/problems/missing-number-in-arithmetic-progression/

package missingNumberInArithmeticProgression;

class Solution {

	// time complexity: O(logn)
	// space complexity: O(1)
    public int missingNumber(int[] arr) {
		if (arr == null || arr.length == 0)
			return -1;

		int d = (arr[arr.length - 1] - arr[0]) / arr.length;
		int left = 0;
		int right = arr.length - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] == arr[0] + d * mid)
				left = mid + 1;
			else if (arr[mid] - arr[mid - 1] != d)
				return arr[mid - 1] + d;
			else
				right = mid;
		}

		return arr[left] - d;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int missingNumberLinear(int[] arr) {
		if (arr == null || arr.length == 0)
			return -1;

		int delta = (arr[arr.length - 1] - arr[0]) / arr.length;
		if (delta == 0)
			return arr[0];
		for (int i = 0; i < arr.length - 1; ++i) {
			if (arr[i + 1] - arr[i] != delta)
				return arr[i] + delta;
		}

		return -1;
    }
}
