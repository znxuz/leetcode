// https://leetcode.com/problems/flood-fill/

package floodFill;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

    public int[][] floodFill(int[][] image, int r, int c, int newColor) {
		return floodFillBFS(image, r, c, newColor);
	}

	// BFS
	// time complexity: O(n * m)
	// space complexity: O(n * m)
    public int[][] floodFillBFS(int[][] image, int r, int c, int newColor) {
		if (image[r][c] == newColor)
			return image;

		int[] dirs = {0, 1, 0, -1, 0};
		Deque<int[]> stack = new ArrayDeque<>();
		int oldColor = image[r][c];
		image[r][c] = newColor;
		stack.offer(new int[]{r, c});
		while (!stack.isEmpty()) {
			int[] idx = stack.poll();

			for (int i = 0; i < 4; i++) {
				int row = idx[0] + dirs[i];
				int col = idx[1] + dirs[i + 1];
				if (row < 0 || row == image.length
						|| col < 0 || col == image[idx[0]].length
						|| image[row][col] != oldColor)
					continue;
				image[row][col] = newColor;
				stack.offer(new int[]{row, col});
			}
		}

		return image;
	}

    public int[][] floodFillDFS(int[][] image, int r, int c, int newColor) {
		int color = image[r][c];
		if (color != newColor)
			floodFillRec(image, r, c, color, newColor);
		return image;
    }

	// DFS
	// time complexity: O(n * m)
	// space complexity: O(n * m)
	private void floodFillRec(int[][] image, int r, int c, int color, int newColor) {
		if (r < 0 || c < 0
				|| r == image.length || c == image[r].length
				|| image[r][c] != color)
			return;

		image[r][c] = newColor;
		floodFillRec(image, r, c + 1, color, newColor);
		floodFillRec(image, r + 1, c, color, newColor);
		floodFillRec(image, r, c - 1, color, newColor);
		floodFillRec(image, r - 1, c, color, newColor);
	}

}
