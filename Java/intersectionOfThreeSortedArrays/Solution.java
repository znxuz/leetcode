// https://leetcode.com/problems/intersection-of-three-sorted-arrays/

package intersectionOfThreeSortedArrays;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
		int i, j, k;
		i = j = k = 0;
		List<Integer> list = new ArrayList<>();
		while (i < arr1.length && j < arr2.length && k < arr3.length) {
			if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
				list.add(arr1[i]);
				i++;
				j++;
				k++;
			} else if (arr1[i] > arr2[j] || arr1[i] > arr3[k]) {
				if (arr1[i] > arr2[j])
					j++;
				if (arr1[i] > arr3[k])
					k++;
			} else {
				i++;
			}
		}

		return list;
	}

	// counting sort
	// time complexity: O(3n) = O(n)
	// space complexity: O(n)
    public List<Integer> arraysIntersectionCountingSort(int[] arr1, int[] arr2, int[] arr3) {
		int max = Math.max(arr1[arr1.length - 1], Math.max(arr2[arr2.length - 1], arr3[arr3.length - 1]));
		int[] bucket = new int[max + 1];
		for (int n : arr1)
			bucket[n]++;
		for (int n : arr2)
			bucket[n]++;
		for (int n : arr3)
			bucket[n]++;
		List<Integer> list = new ArrayList<>();
		for (int i = 0; i < bucket.length; ++i) {
			if (bucket[i] == 3)
				list.add(i);
		}

		return list;
    }
}
