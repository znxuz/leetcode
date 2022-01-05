// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

package theKWeakestRowInMatrix;

import java.util.PriorityQueue;

class Solution {

	// time complexity: O(row * col)
	// space complexity: O(1)
    public int[] kWeakestRows(int[][] matrix, int k) {
		int row = matrix.length;
		int col = matrix[0].length;
		int[] res = new int[k];
		int idx = 0;

		for (int j = 0; j < col && idx < res.length; ++j) {
			for (int i = 0; i < row && idx < res.length; ++i) {
				if (matrix[i][j] == 0 && (j == 0 || matrix[i][j - 1] != 0)) {
					res[idx++] = i;
				}
			}
		}
		for (int i = 0; i < row && idx < res.length; ++i) {
			if (matrix[i][col - 1] == 1)
				res[idx++] = i;
		}

		return res;
	}

	// time complexity: O(row * col + row * log(row))
	// space complexity: O(row)
    public int[] kWeakestRowsPriorityQueue(int[][] matrix, int k) {
		PriorityQueue<int[]> pq = new PriorityQueue<>((a1, a2) -> {
			int res = Integer.compare(a1[1], a2[1]);
			return (res != 0) ? res : Integer.compare(a1[0], a2[0]);
		});
		for (int i = 0; i < matrix.length; ++i)
			pq.offer(new int[]{i, lastOneIdx(matrix[i])});

		int[] res = new int[k];
		for (int i = 0; i < res.length; ++i)
			res[i] = pq.poll()[0];
		return res;
		// return Stream.generate(pq::poll).limit(k).mapToInt(a -> a[0]).toArray();
		// stream of PriorityQueue does not preserve the order!
    }

	public int lastOneIdx(int[] row) {
		int l = 0;
		int r = row.length - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (row[m] == 1)
				l = m + 1;
			else
				r = m;
		}

		return row[l] == 1 ? l : l - 1;
	}
}
