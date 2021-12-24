// https://leetcode.com/problems/height-checker/

package heightChecker;

import java.util.Arrays;

class Solution {

	// counting sort idea
	// time complexity: O(n)
	// space complexity: O(1)
    public int heightChecker(int[] heights) {
		int[] ctr = new int[101]; // constraints are set with 101
		for (int h : heights)
			ctr[h]++;

		int count = 0;
		int idx = 0;
		for (int h : heights) {
			while (ctr[idx] == 0)
				idx++;
			if (h != idx)
				count++;
			ctr[idx]--;
		}

		return count;
    }

	// time complexity: O(n logn)
	// space complexity: O(n)
    public int heightCheckerSort(int[] heights) {
		var sorted = Arrays.copyOf(heights, heights.length);
		Arrays.sort(sorted);

		int count = 0;
		for (int i = 0; i < heights.length; ++i) {
			if (heights[i] != sorted[i])
				count++;
		}

		return count;
    }

}
