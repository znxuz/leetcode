// https://leetcode.com/problems/flipping-an-image/

package flippingAnImage;

class Solution {

    public int[][] flipAndInvertImage(int[][] image) {
		int[][] flipped = new int[image.length][image[0].length];
		for (int i = 0; i < image.length; i++) {
			for (int j = 0; j < image[i].length; j++) {
				flipped[i][j] = image[i][image[i].length - 1 - j] == 0 ? 1 : 0;
			}
		}

		return flipped;
    }

}
