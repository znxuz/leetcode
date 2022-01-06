// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

package findTheDistanceValueBetweenTwoArrays;

class Solution {

	// counting sort
	// time complexity: O(n + m)
	// space complexity: O(1)
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
		int limit = 1000;
		int[] bounds = new int[limit * 2 + 1];
		for (int n : arr2) {
			bounds[n + limit]++;
		}

		int ctr = 0;
		for (int n : arr1) {
			int start = n + limit - d;
			int end = Math.min(bounds.length - 1, n + limit + d);
			while (start <= end) {
				if (start > 0 && bounds[start] != 0)
					break;
				start++;
			}
			if (start > end)
				ctr++;
		}

		return ctr;
	}

	// time complexity: O(n * m): n = arr1.length, m = arr2.length
	// space complexity: O(1)
    public int findTheDistanceValueBruteForce(int[] arr1, int[] arr2, int d) {
		int ctr = 0;
		for (int i = 0; i < arr1.length; ++i) {
			int j = 0;
			while (j < arr2.length && Math.abs(arr1[i] - arr2[j]) > d)
				j++;
			if (j == arr2.length)
				ctr++;
		}

		return ctr;
    }
}
