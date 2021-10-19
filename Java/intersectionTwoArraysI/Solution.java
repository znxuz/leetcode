// https://leetcode.com/problems/intersection-of-two-arrays/

package intersectionTwoArraysI;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {

    public int[] intersection(int[] nums1, int[] nums2) {
		Set<Integer> set = new HashSet<>();
		for (int num : nums1)
			set.add(num);

		List<Integer> list = new ArrayList<>();
		for (int num : nums2) {
			if (set.contains(num)) {
				list.add(num);
				set.remove(num);
			}
		}

		int[] arr = new int[list.size()];
		for (int i = 0; i < arr.length; i++)
			arr[i] = list.get(i);
		return arr;
	}

    public int[] intersectionStream(int[] nums1, int[] nums2) {
		Set<Integer> set = new HashSet<>();
		for (int i : nums2)
			set.add(i);
		return Arrays.stream(nums1).filter(set::contains).distinct().toArray();
    }
}
