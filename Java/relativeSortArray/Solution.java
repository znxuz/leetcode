// https://leetcode.com/problems/relative-sort-array/

package relativeSortArray;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

class Solution {

	// counting sort
	// time complexity: O(n)
	// space complexity: O(1)
    public int[] relativeSortArrayCountingSort(int[] arr1, int[] arr2) {
		int[] ctr = new int[1001];
		for (int n : arr1)
			ctr[n]++;
		int i = 0;
		for (int n : arr2) {
			while (ctr[n]-- > 0)
				arr1[i++] = n;
		}
		for (int j = 0; j < ctr.length; ++j) {
			while (ctr[j]-- > 0)
				arr1[i++] = j;
		}

		return arr1;
	}

	// counting sort without constraint
	// time complexity: O(n logn)
	// space complexity: O(n)
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
		Map<Integer, Integer> treemap = new TreeMap<>();
		for (int n : arr1)
			treemap.put(n, treemap.getOrDefault(n, 0) + 1);
		int i = 0;
		for (int n : arr2) {
			for (int j = 0; j < treemap.get(n); ++j) {
				arr1[i++] = n;
			}
			treemap.remove(n);
		}
		for (var n : treemap.keySet()) {
			for (int j = 0; j < treemap.get(n); ++j)
				arr1[i++] = n;
		}

		return arr1;
	}

    public int[] relativeSortArrayComparator(int[] arr1, int[] arr2) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < arr2.length; ++i)
			map.put(arr2[i], i);
		Comparator<Integer> comp = (i1, i2) -> {
			if (map.containsKey(i1) && map.containsKey(i2))
				return Integer.compare(map.get(i1), map.get(i2));
			if (map.containsKey(i1)) // TODO why return -1 and not 1?
				return -1;
			if (map.containsKey(i2))
				return 1;
			return Integer.compare(i1, i2);
		};

		return Arrays.stream(arr1).boxed().sorted(comp).mapToInt(Integer::intValue).toArray();
    }
}
