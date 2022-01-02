// https://leetcode.com/problems/shift-2d-grid/

package shift2DGrid;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// calc start row with k / grid.col instead of k / grid.row
	// time complexity: O(n * m)
	// space complexity: O(1)
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
		int total = grid.length * grid[0].length;
		k = (total - (k % total)) % total;
		int row = k / grid[0].length;
		int col = k % grid[0].length;
		List<List<Integer>> newgrid = new ArrayList<>();
		for (int i = 0; i < grid.length; ++i) {
			newgrid.add(new ArrayList<>());
			for (int j = 0; j < grid[i].length; ++j) {
				newgrid.get(i).add(grid[row][col]);
				col = ++col % grid[i].length;
				if (col == 0)
					row = ++row % grid.length;
			}
		}

		return newgrid;
    }
}
