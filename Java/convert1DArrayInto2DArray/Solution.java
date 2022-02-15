// https://leetcode.com/problems/convert-1d-array-into-2d-array/

package convert1DArrayInto2DArray;

class Solution {

    public int[][] construct2DArray(int[] original, int row, int col) {
		if (row * col != original.length)
			return new int[0][0];

		int[][] arr = new int[row][col];
		int idx = 0;
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[i].length; ++j)
				arr[i][j] = original[idx++];
		}

		return arr;
    }
}
