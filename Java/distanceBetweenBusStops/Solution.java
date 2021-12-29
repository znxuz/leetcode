// https://leetcode.com/problems/distance-between-bus-stops/

package distanceBetweenBusStops;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int distanceBetweenBusStops(int[] distance, int start, int end) {
		int forwardPath = 0;
		int backwardPath = 0;
		int i = start;
		int j = end;
		while (i != end || j != start) {
			if (i != end) {
				forwardPath += distance[i];
				i = ++i % distance.length;
			}
			if (j != start) {
				backwardPath += distance[j];
				j = ++j % distance.length;
			}
		}
		return Math.min(forwardPath, backwardPath);
    }
}
