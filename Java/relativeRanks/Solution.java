// https://leetcode.com/problems/relative-ranks/

package relativeRanks;

import java.util.Arrays;

class Solution {

    public String[] findRelativeRanks(int[] scores) {
		// boxed Integer for Arrays.sort
		Integer[] ordered = new Integer[scores.length];

		for (int i = 0; i < scores.length; i++) {
			ordered[i] = i;
		}

		// use scores array to sort rank array
		Arrays.sort(ordered, (a, b) -> (scores[b] - scores[a]));

		String[] ranks = new String[scores.length];

		for (int i = 0; i < scores.length; i++) {
			if (i == 0) {
				ranks[ordered[i]] = "Gold Medal";
			} else if (i == 1) {
				ranks[ordered[i]] = "Silver Medal";
			} else if (i == 2) {
				ranks[ordered[i]] = "Bronze Medal";
			} else {
				ranks[ordered[i]] = String.valueOf(i + 1);
			}
		}

		return ranks;	
	}

}
