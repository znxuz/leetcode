// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

package detectPatternOfLengthMRepeatedKOrMoreTimes;

class Solution {

	// idea: reset counter if current != current + m; return true if counter is enough((k - 1) *m)
	// time complexity: O(n)
	// space complexity: O(1)
    public boolean containsPattern(int[] arr, int m, int k) {
		int cnt = 0;
		for (int i = 0; i + m < arr.length; ++i) {
			if (arr[i] != arr[i + m]) {
				cnt = 0;
				continue;
			}
			cnt++;
			if (cnt == m * (k - 1))
				return true;
		}

		return false;
	}

	// time complexity: O(n * m * k)
	// space comleixity: O(1)
    public boolean containsPatternBruteForce(int[] arr, int m, int k) {
		int window = m * k;
		for (int i = 0; i + window <= arr.length; ++i) {
			if (checkPattern(arr, i, m, k))
				return true;
		}
		return false;
    }

	private boolean checkPattern(int[] arr, int i, int m, int k) {
		for (int j = i + m; j < i + m * k; j += m) {
			for (int l = j; l < j + m; ++l) {
				if (arr[l - m] != arr[l])
					return false;
			}
		}

		return true;
	}
}
