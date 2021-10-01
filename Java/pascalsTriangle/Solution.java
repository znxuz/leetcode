// https://leetcode.com/problems/pascals-triangle/

package pascalsTriangle;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n^2); n = numRows
	// 		1 + 2 + 3 + ... + n = n(n + 1) / 2
	// 			-> O(n^2)
	// space complexity: O(n^2) for storing each num
    public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> triangle = new ArrayList<>();

		for (int i = 0; i < numRows; i++) {
			List<Integer> currentRow = new ArrayList<>();
			List<Integer> prevRow = i == 0 ? null : triangle.get(i - 1);
			for (int j = 0; j <= i; j++) {
				int prev = 0;
				int current = 1;
				if (i != 0) {
					prev = j == 0 ? 0 : j == i ? 0 : prevRow.get(j - 1);
					current = j == i ? 1 : prevRow.get(j);
				}
				currentRow.add(prev + current);
			}
			triangle.add(currentRow);
		}

		return triangle;
    }
}
