// https://leetcode.com/problems/intersection-of-two-arrays-ii/

package intersectionTwoArraysII;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

	// time complexity: O(n * logn + m * logm)
	// space completixy: implementation defined
    public int[] intersect(int[] nums1, int[] nums2) {
		Arrays.sort(nums1);
		Arrays.sort(nums2);

		List<Integer> list = new ArrayList<>();
		for (int i = 0, j = 0; i < nums1.length && j < nums2.length;) {
			if (nums1[i] < nums2[j]) {
				i++;
	 		} else if (nums1[i] > nums2[j]) {
				j++;
			} else {
				int num = nums1[i];
				int repeat1 = 0;
				while (i < nums1.length && j < nums2.length
						&& nums1[i] == nums2[j] && nums1[i] == num) {
					repeat1++;
					i++;
					j++;
				}
				while (repeat1-- > 0)
					list.add(num);
			}
		}

		int[] ret = new int[list.size()];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = list.get(i);
		}

		return ret;
	}

	// time complexity: O(n) if map.get O(1)
	// space complexity: O(n)
    public int[] intersectMap(int[] nums1, int[] nums2) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i : nums1)
			map.put(i, map.getOrDefault(i, 0) + 1);

		List<Integer> list = new ArrayList<>();
		for (int i : nums2) {
			if (map.containsKey(i) && map.get(i) > 0) {
				list.add(i);
				map.put(i, map.get(i) - 1);
			}
		}

		int[] ret = new int[list.size()];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = list.get(i);
		}

		return ret;
    }
}
