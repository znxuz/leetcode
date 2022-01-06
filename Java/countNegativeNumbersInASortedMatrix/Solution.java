// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

package countNegativeNumbersInASortedMatrix;

class Solution {

	// time complexity: O(n logm): n for grid.length, m for grid.width
	// space complexity: O(n)
    public int countNegatives(int[][] grid) {
		int[] negIdx = new int[grid.length];
		for (int i = 0; i < grid.length; ++i)
			negIdx[i] = getFirstNegIdx(grid[i]);

		int ctr = 0;
		for (int i : negIdx)
			ctr += grid[0].length - i;

		return ctr;
    }

	// binary search with hi idx = last idx
	public int getFirstNegIdx(int[] row) {
		int lo = 0;
		int hi = row.length - 1;
		while (lo < hi) {
			int md = lo + (hi - lo) / 2;
			if (row[md] < 0)
				hi = md;
			else
				lo = md + 1;
		}

		return row[lo] < 0 ? lo : lo + 1;
	}

	// binary search with hi idx = array length
	public int getFirstNegIdx2(int[] row) {
		int lo = 0;
		int hi = row.length;
		while (lo < hi) {
			int md = lo + (hi - lo) / 2;
			if (row[md] < 0)
				hi = md;
			else
				lo = md + 1;
		}

		return lo;
	}
}
