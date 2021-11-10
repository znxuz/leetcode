// https://leetcode.com/problems/reshape-the-matrix/

package reshapeTheMatrix;

class Solution {

    public int[][] matrixReshape(int[][] mat, int r, int c) {
		if (mat == null)
			return null;
		if (mat.length * mat[0].length != r * c)
			return mat;

		int[][] newMat = new int[r][c];
		int matR = 0;
		int matC = 0;
		for (int i = 0; i < newMat.length; i++) {
			for (int j = 0; j < newMat[i].length; j++) {
				if (matC == mat[matR].length)
					matR++;
				matC = matC % mat[matR].length;
				newMat[i][j] = mat[matR][matC];
				matC++;
			}
		}

		return newMat;
    }
}
