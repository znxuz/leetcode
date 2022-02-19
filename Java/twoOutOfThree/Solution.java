// https://leetcode.com/problems/two-out-of-three/

package twoOutOfThree;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
		int[][] flags = new int[3][101];
		for (int n : nums1)
			flags[0][n] = 1;
		for (int n : nums2)
			flags[1][n] = 1;
		for (int n : nums3)
			flags[2][n] = 1;

		List<Integer> list = new ArrayList<>();
		for (int i = 1; i < flags[0].length; ++i)
			if (flags[0][i] + flags[1][i] + flags[2][i] > 1)
				list.add(i);

		return list;
	}

}
