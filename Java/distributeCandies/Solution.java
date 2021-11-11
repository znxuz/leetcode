// https://leetcode.com/problems/distribute-candies/

package distributeCandies;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int distributeCandies(int[] candyType) {
		Set<Integer> set = new HashSet<>();
		for (int i : candyType)
			set.add(i);
		return Math.min(set.size(), candyType.length / 2);
	}

	// time complexity: O(n logn)
	// spcae complexity: O(1)
    public int distributeCandiesSort(int[] candyType) {
		int limit = candyType.length / 2;

		Arrays.sort(candyType);
		int count = 1;
		int prev = candyType[0];
		for (int i = 1; i < candyType.length; i++) {
			if (candyType[i] == prev)
				continue;
			count++;
			prev = candyType[i];
		}

		return Math.min(limit, count);
	}

	// time complexity: stream
	// space complexity: stream
    public int distributeCandiesStream(int[] candyType) {
		return (int) Arrays.stream(candyType)
			.distinct()
			.limit(candyType.length / 2)
			.count();
    }
}
