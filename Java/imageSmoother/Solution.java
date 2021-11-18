// https://leetcode.com/problems/image-smoother/

package imageSmoother;

class Solution {

	private int roundDown(int[][] img, int i, int j) {
		int sum = 0;
		int count = 0;
		for (int k = -1; k < 2; k++) {
			for (int l = -1; l < 2; l++) {
				int neighborX = (i + k < 0 || i + k >= img.length) ? -1 : i + k;
				int neighborY = (j + l < 0 || j + l >= img[i].length) ? -1 : j + l;
				if (neighborX == -1 || neighborY == -1)
					continue;
				sum += img[neighborX][neighborY];
				count++;
			}
		}

		return sum / count;
	}

    public int[][] imageSmoother(int[][] img) {
		int[][] smoother = new int[img.length][];
		for (int i = 0; i < img.length; i++) {
			smoother[i] = new int[img[i].length];
			for (int j = 0; j < img[i].length; j++) {
				smoother[i][j] = roundDown(img, i, j);
			}
		}

		return smoother;
    }
}
