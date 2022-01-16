// https://leetcode.com/problems/matrix-diagonal-sum/

package matrixDiagonalSum;

class Solution {

	// time complexity: O(n): n = matrix.length
	// space complexity: O(1)
    public int diagonalSum(int[][] matrix) {
		// check for matrix validity
		int n = matrix.length;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int j = n - 1 - i;
			if (i == j)
				sum += matrix[i][i];
			else
				sum += matrix[i][i] + matrix[i][j];
		}

		return sum;
    }
}
