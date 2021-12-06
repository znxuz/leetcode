// https://leetcode.com/problems/peak-index-in-a-mountain-array/

package peakIndexInMountainArray;

class Solution {

	// time complexity: O(logn)
	// space compleixty: O(1)
    public int peakIndexInMountainArray(int[] arr) {
		return binarySearch(arr, 1, arr.length - 2);
	}

	private int binarySearch(int[] arr, int left, int right) {
		if (left == right)
			return left;

		int mid = left + (right - left) / 2;
		if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
			return mid;
		else if (arr[mid - 1] < arr[mid])
			return binarySearch(arr, mid + 1, right);
		return binarySearch(arr, left, mid);
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int peakIndexInMountainArrayLinear(int[] arr) {
		int i = 0;
		while (arr[i] < arr[i + 1])
			i++;

		return i;
    }
}
