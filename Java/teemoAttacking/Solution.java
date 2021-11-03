// https://leetcode.com/problems/teemo-attacking/

package teemoAttacking;

class Solution {

    public int findPoisonedDuration(int[] timeSeries, int duration) {
		if (timeSeries.length == 0)
			return 0;

		int total = 0;
		for (int i = 0; i < timeSeries.length - 1; i++) {
			int begin = timeSeries[i];
			int next = timeSeries[i + 1];
			total += Math.min(next - begin, duration);
		}

		return total + duration;
    }
}
