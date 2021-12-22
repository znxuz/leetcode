// https://leetcode.com/problems/matrix-cells-in-distance-order/

package matrixCellsInDistanceOrder;

import java.util.Arrays;
import java.util.Comparator;

class Solution {

	public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
		int[][] arr = new int[rows * cols][];
		int idx = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				arr[idx++] = new int[]{i, j};
			}
		}

		Comparator<int[]> comp = (a1, a2) -> Integer.compare(
				Math.abs(a1[0] - rCenter) + Math.abs(a1[1] - cCenter),
				Math.abs(a2[0] - rCenter) + Math.abs(a2[1] - cCenter));
		Arrays.sort(arr, comp);
		return arr;
	}
}
