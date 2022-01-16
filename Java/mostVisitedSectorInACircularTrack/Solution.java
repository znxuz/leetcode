// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

package mostVisitedSectorInACircularTrack;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public List<Integer> mostVisited(int n, int[] rounds) {
		int start = rounds[0];
		int end = rounds[rounds.length - 1];
		List<Integer> res = new ArrayList<>();
		if (start <= end) {
			for (int i = start; i <= end; ++i)
				res.add(i);
		} else {
			for (int i = 1; i <= end; ++i)
				res.add(i);
			for (int i = start; i <= n; ++i)
				res.add(i);
		}

		return res;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public List<Integer> mostVisitedSimulation(int n, int[] rounds) {
		int[] cnts = new int[n + 1];
		int i = 0;
		int round = rounds[0];
		int max = 0;
		do {
			cnts[round]++;
			if (round == rounds[i]) {
				max = Math.max(max, cnts[round]);
				i++;
			}
			round = Math.max(1, (round + 1) % (n + 1));
		} while (i < rounds.length);

		List<Integer> res = new ArrayList<>();
		for (int j = 0; j < cnts.length; ++j) {
			if (cnts[j] == max)
				res.add(j);
		}

		return res;
	}
}
