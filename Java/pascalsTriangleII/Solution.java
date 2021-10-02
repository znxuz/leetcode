// https://leetcode.com/problems/pascals-triangle-ii/

package pascalsTriangleII;

import java.util.ArrayList;
import java.util.List;

class Solution {

	@SuppressWarnings("unused")
	private int getNum(int row, int col) {
		if (row == 0 || col == 0 || col == row)
			return 1;
		return getNum(row - 1, col - 1) + getNum(row - 1, col);
	}

	private int getNumMemoi(int[][] triangle, int row, int col) {
		if (triangle[row][col] != 0)
			return triangle[row][col];

		if (row == 0 || col == 0 || col == row) {
			triangle[row][col] = 1;
		} else {
			triangle[row][col] = getNumMemoi(triangle, row - 1, col - 1)
				+ getNumMemoi(triangle, row - 1, col);
		}
		return triangle[row][col];
	}

	// time complexity: O(2^n)
	// space complexity: O(n)
    public List<Integer> getRow(int rowIndex) {
		int[][] triangle = new int[rowIndex + 1][rowIndex + 1];
		List<Integer> row = new ArrayList<>();

		for (int i = 0; i <= rowIndex; i++) {
			row.add(getNumMemoi(triangle, rowIndex, i));
		}

		return row;
    }
}
