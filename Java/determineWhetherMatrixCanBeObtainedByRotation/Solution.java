// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

package determineWhetherMatrixCanBeObtainedByRotation;

class Solution {

	// time complexity: O(3 * n * n) = O(n)
	// space complexity: O(n * n)
    public boolean findRotation(int[][] mtrx, int[][] target) {
		int n = mtrx.length;
		for (int k = 0; k < 4; ++k) {
			int[][] rotated = new int[n][n];
			boolean isEqual = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (mtrx[i][j] != target[i][j])
						isEqual = false;
					rotated[j][n - 1 - i] = mtrx[i][j];
				}
			}
			if (isEqual)
				return true;
			mtrx = rotated;
		}

		return false;
    }
}
