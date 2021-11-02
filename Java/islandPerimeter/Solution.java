// https://leetcode.com/problems/island-perimeter/

package islandPerimeter;

class Solution {

	private int countPerimeter(int[][] grid, int row, int col) {
		int count = 0;

		boolean left = col == 0 ? true : grid[row][col - 1] == 0;
		boolean right = col == grid[row].length - 1 ?
			true : grid[row][col + 1] == 0;
		boolean top = row == 0 ? true : grid[row - 1][col] == 0;
		boolean bottom = row == grid.length - 1 ?
			true : grid[row + 1][col] == 0;
		if (left)
			count++;
		if (right)
			count++;
		if (top)
			count++;
		if (bottom)
			count++;
		return count;
	}

    public int islandPerimeter(int[][] grid) {
		int perimeter = 0;
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				if (grid[i][j] == 1)
					perimeter += countPerimeter(grid, i, j);
			}
		}

		return perimeter;
    }
}
