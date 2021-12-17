// https://leetcode.com/problems/fixed-point/

package fixedPoint;

class Solution {

    public int fixedPoint(int[] arr) {
		return binarySearchIter(arr, 0, arr.length - 1);
	}

	public int binarySearchIter(int[] arr, int left, int right) {
		int ret = -1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] < mid) {
				left = mid + 1;
				continue;
			}
			if (arr[mid] == mid)
				ret = mid;
			right = mid;
		}

		return ret;
	}

	// time complexity: O(logn)
	// space complexity: O(n)
	public int binarySearchRec(int[] arr, int left, int right) {
		if (left == right)
			return arr[left] == left ? left : -1;

		int mid = left + (right - left) / 2;
		if (arr[mid] > mid)
			return binarySearchRec(arr, left, mid);
		if (arr[mid] == mid) {
			int prev = binarySearchRec(arr, left, mid);
			return prev == -1 ? mid : prev;
		}
		return binarySearchRec(arr, mid + 1, right);
	}

}
