// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

package findNearestPointThatHasTheSameXOrYCoordinate;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int nearestValidPoint(int x, int y, int[][] points) {
		int idx = -1;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < points.length; ++i) {
			int x1 = points[i][0];
			int y1 =points[i][1];
			if (x == x1 || y == y1) {
				int distance = Math.abs(x - x1) + Math.abs(y - y1);
				if (distance < min) {
					min = distance;
					idx = i;
				}
			}
		}

		return idx;
    }
}
