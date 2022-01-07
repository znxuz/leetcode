// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

package luckyNumbersInMatrix;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n * m)
	// space complexity: O(1)
	public List<Integer> luckyNumbers(int[][] matrix) {
		int minMax = Integer.MIN_VALUE;
		int maxMin = Integer.MAX_VALUE;
		for (int i = 0; i < matrix.length; ++i) {
			int min = matrix[i][0];
			for (int j = 1; j < matrix[i].length; ++j)
				min = Math.min(min, matrix[i][j]);
			minMax = Math.max(minMax, min);
		}
		for (int j = 0; j < matrix[0].length; ++j) {
			int max = matrix[0][j];
			for (int i = 1; i < matrix.length; ++i)
				max = Math.max(max, matrix[i][j]);
			maxMin = Math.min(maxMin, max);
		}
		List<Integer> res = new ArrayList<>();
		if (minMax == maxMin)
			res.add(minMax);
		return res;
	}

}
