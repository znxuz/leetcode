// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

package cellsWithOddValuesInMatrix;

class Solution {

	// time complexity: O(indices.length + (m * n))
	// space complexity: O(m + n)
    public int oddCells(int m, int n, int[][] indices) {
		boolean[] row = new boolean[m];
		boolean[] col = new boolean[n];
		for (var idx : indices) {
			row[idx[0]] ^= true;
			col[idx[1]] ^= true;
		}

		int ctr = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				ctr += (row[i] ^ col[j]) ? 1 : 0;
			}
		}

		return ctr;
	}

	// time complexity: O(indices.length * (m + n) + (m * n))
	// space complexity: O(m * n)
    public int oddCellsMatrix(int m, int n, int[][] indices) {
		int[][] matrix = new int[m][n];
		for (var pair : indices) {
			for (int i = 0; i < n; ++i)
				matrix[pair[0]][i]++;
			for (int i = 0; i < m; ++i)
				matrix[i][pair[1]]++;
		}
		int ctr = 0;
		for (var row : matrix) {
			for (var cell : row)
				ctr += (cell & 1) == 1 ? 1 : 0;
		}

		return ctr;
    }
}
