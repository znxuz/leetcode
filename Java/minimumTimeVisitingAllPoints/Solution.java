// https://leetcode.com/problems/minimum-time-visiting-all-points/

package minimumTimeVisitingAllPoints;

class Solution {

	// time complexity; O(n)
	// space complexity: O(1)
    public int minTimeToVisitAllPoints(int[][] points) {
		int time = 0;
		for (int i = 0; i < points.length - 1; ++i) {
			time += Math.max(Math.abs(points[i + 1][0] - points[i][0]),
					Math.abs(points[i + 1][1] - points[i][1]));
		}

		return time;
    }

}
