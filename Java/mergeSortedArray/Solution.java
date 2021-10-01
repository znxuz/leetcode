// https://leetcode.com/problems/merge-sorted-array/

package mergeSortedArray;

import java.util.Arrays;

class Solution {

	// better approach
	// time complexity: O(m + n)
	// space complexity: O(1) for not using extra array
    public void merge(int[] nums1, int m, int[] nums2, int n) {
		int lastIndex = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		while (i >= 0 && j >= 0)
			nums1[lastIndex--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
		while (i >= 0)
			nums1[lastIndex--] = nums1[i--];
		while (j >= 0)
			nums1[lastIndex--] = nums2[j--];
	}

	// time complexity: O(2m + n) = O(m + n)
	// space complexity: O(m)
    public void merge1(int[] nums1, int m, int[] nums2, int n) {
		int[] half = Arrays.copyOf(nums1, m);

		int index, i, j;
		index = i = j = 0;
		while (i < m && j < n)
			nums1[index++] = half[i] <= nums2[j] ? half[i++] : nums2[j++];

		while (i < m)
			nums1[index++] = half[i++];
		while (j < n)
			nums1[index++] = nums2[j++];
    }
}
