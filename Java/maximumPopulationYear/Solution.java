// https://leetcode.com/problems/maximum-population-year/

package maximumPopulationYear;

class Solution {

	// line sweep
	// time complexity: O(n)
	// space complexity: O(1)
    public int maximumPopulation(int[][] logs) {
		int offset = 1950;
		int[] marks = new int[101];
		for (var entry : logs) {
			marks[entry[0] - offset]++;
			marks[entry[1] - offset]--;
		}

		int res = 0;
		for (int i = 1; i < marks.length; ++i) {
			marks[i] += marks[i - 1];
			res = marks[i] > marks[res] ? i : res;
		}

		return res + offset;
    }
}
