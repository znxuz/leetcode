// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

package sumOfAllOddLengthSubarrays;

class Solution {

	// math formula: times for each num at index i:
	// 	((i + 1) * (n - i) + 1) / 2
    public int sumOddLengthSubarrays(int[] arr) {
		int res = 0;
		int n = arr.length;
		for (int i = 0; i < n; ++i) {
			res += ((i + 1) * (n - i) + 1) / 2 * arr[i];
		}

		return res;
	}

    public int sumOddLengthSubarraysBruteForce(int[] arr) {
		int sum = 0;
		for (int i = 1; i <= arr.length; i += 2) {
			for (int j = 0; j < arr.length; ++j) {
				if (j + i > arr.length)
					break;
				for (int k = j; k < j + i; ++k)
					sum += arr[k];
			}
		}

		return sum;
    }
}
