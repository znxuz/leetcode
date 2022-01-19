// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

package specialPositionsInABinaryMatrix;

class Solution {

	// time complexity: O(n * m)
	// space complexity: O(n + m)
    public int numSpecial(int[][] mat) {
		int[] rows = new int[mat.length];
		int[] cols = new int[mat[0].length];
		for (int i = 0;i < mat.length; ++i) {
			for (int j = 0; j < mat[i].length; ++j) {
				if (mat[i][j] == 1) {
					rows[i]++;
					cols[j]++;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < mat.length; ++i) {
			for (int j = 0; j < mat[i].length; ++j) {
				if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)
					cnt++;
			}
		}

		return cnt;
	}

	// time complexity: O(n * m * (n + m))
	// space complexity: O(1)
    public int numSpecialBruteForce(int[][] mat) {
		int cnt = 0;
		int n = mat.length;
		int m = mat[0].length;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == 0)
					continue;
				int sum = 0;
				for (int k = (i + 1) % n; k != i; k = (k + 1) % n) {
					sum += mat[k][j];
				}
				for (int k = (j + 1) % m; k != j; k = (k + 1) % m) {
					sum += mat[i][k];
				}
				if (sum == 0)
					cnt++;
			}
		}

		return cnt;
    }
}
