// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

package elementAppearingMoreThanAQuarterInSortedArray;

class Solution {

	// time complexity: O(n logn)
	// space complexity: O(1)
    public int findSpecialInteger(int[] arr) {
		int offset = arr.length / 4;
		for (int i = 0; i < arr.length; i += offset) {
			int idx = binarysearch(arr, 0, arr.length - 1, arr[i]);
			if (idx + offset < arr.length && arr[idx + offset] == arr[idx])
				return arr[idx];
		}

		return -1;
	}

	public int binarysearch(int[] arr, int l, int r, int t) {
		if (l == r)
			return l;

		int m = l + (r - l) / 2;
		if (arr[m] < t)
			return binarysearch(arr, m + 1, r, t);
		return binarysearch(arr, l, m, t);
	}

	// time complexity: O(n)
	// space compelxity: O(1)
    public int findSpecialIntegerLinear(int[] arr) {
		int count = arr.length / 4;
		int prev = -1;
		int ctr = 0;
		for (int n : arr) {
			if (n == prev)
				ctr++;
			else
				ctr = 0;
			if (ctr >= count)
				return n;
			prev = n;
		}

		return -1;
    }
}
