// https://leetcode.com/problems/toeplitz-matrix/

package toeplitzMatrix;

import java.util.LinkedList;

class Solution {

	// time complexity: O(n): n for row * col
	// space complexity: O(1)
    public boolean isToeplitzMatrix(int[][] matrix) {
		for (int i = 0; i < matrix.length - 1; i++) {
			for (int j = 0; j < matrix[i].length - 1; j++) {
				if (matrix[i][j] != matrix[i + 1][j + 1])
					return false;
			}
		}

		return true;    
	}

    public boolean isToeplitzMatrixFollowUp(int[][] matrix) {
		LinkedList<Integer> list = new LinkedList<>();
		for (int i = 0; i < matrix.length; i++) {
			if (!checkOneRow(matrix[i], list))
				return false;
		}

		return true;
	}

	private boolean checkOneRow(int[] row, LinkedList<Integer> list) {
		if (list.isEmpty()) {
			for (int i : row)
				list.addLast(i);
			return true;
		}

		for (int i = 0; i < row.length; i++) {
			if (i == 0)
				list.addFirst(row[i]);
			else if (list.get(i) != row[i]) {
				return false;
			}
		}
		list.removeLast();

		return true;
	}
}
