// https://leetcode.com/problems/check-array-formation-through-concatenation/

package checkArrayFormationThroughConcatenation;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

	// time compleixty: O(n logn)
	// space complexity: O(n)
    public boolean canFormArray(int[] arr, int[][] pieces) {
		Arrays.sort(pieces, (arr1, arr2) -> Integer.compare(arr1[0], arr2[0]));
		int i = 0;
		while (i < arr.length) {
			int[] match = binarysearch(pieces, arr[i]);
			if (match == null)
				return false;
			int j = 0;
			while (j < match.length) {
				if (i == arr.length || arr[i] != match[j])
					return false;
				i++;
				j++;
			}
			if (j != match.length)
				return false;
		}

		return true;
	}

	private int[] binarysearch(int[][] pieces, int target) {
		int lo = 0;
		int hi = pieces.length - 1;
		while (lo <= hi) {
			int md = lo + (hi - lo) / 2;
			if (pieces[md][0] == target)
				return pieces[md];
			else if (pieces[md][0] < target)
				lo = md + 1;
			else
				hi = md - 1;
		}

		return null;
	}


	// time complexity: O(n)
	// space complexity: O(n)
    public boolean canFormArrayMap(int[] arr, int[][] pieces) {
		Map<Integer, int[]> map = new HashMap<>();
		for (int[] p : pieces) {
			map.put(p[0], p);
		}

		int i = 0;
		while (i < arr.length) {
			if (!map.containsKey(arr[i]))
				return false;
			int[] match = map.get(arr[i]);
			int j = 0;
			while (j < match.length) {
				if (i == arr.length || arr[i] != match[j])
					return false;
				j++;
				i++;
			}
			if (j != match.length)
				return false;
		}

		return true;
	}

	// time complexity: O(n^2)
	// space complexity: O(1)
    public boolean canFormArrayBruteForce(int[] arr, int[][] pieces) {
		for (int[] p : pieces) {
			boolean found = false;
			for (int i = 0; i < arr.length; ++i) {
				if (arr[i] != p[0])
					continue;
				int j = 0;
				while (j < p.length) {
					if (i == arr.length || arr[i] != p[j])
						return false;
					i++;
					j++;
				}
				found = (j == p.length);
			}
			if (!found)
				return false;
		}

		return true;
    }

}
