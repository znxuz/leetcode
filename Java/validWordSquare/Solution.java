// https://leetcode.com/problems/valid-word-square/

package validWordSquare;

import java.util.List;

class Solution {

	private boolean checkDiagonal(char[][] matrix) {
		int k = 0;
		while (k < matrix.length) {
			int i = k;
			int j = k;
			while (i < matrix.length && j < matrix.length) {
				if (matrix[k][i] != matrix[j][k])
					return false;
				i++;
				j++;
			}
			k++;
		}

		return true;
	}

	// time complexity: O(n^2)
	// space complexity: O(n^2)
    public boolean validWordSquare(List<String> words) {
		if (words == null || words.size() == 0)
			return false;
		int squareLen = words.size();
		char[][] matrix = new char[squareLen][squareLen];

		int i = 0;
		for (; i < matrix.length; i++) {
			String w = words.get(i);
			int wLen = w.length();
			int j = 0;
			for (; j < matrix[i].length; j++) {
				matrix[i][j] = j < wLen ? w.charAt(j) : 0;
			}
			if (j < w.length())
				return false;
		}
		if (i != words.size())
			return false;

		return checkDiagonal(matrix);
    }
}
