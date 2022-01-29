// https://leetcode.com/problems/find-the-highest-altitude/

package findTheHighestAltitude;

class Solution {

    public int largestAltitude(int[] gain) {
		int highest = 0;
		int altitude = 0;
		for (int n : gain) {
			altitude += n;
			highest = Math.max(highest, altitude);
		}

		return highest;
    }
}
