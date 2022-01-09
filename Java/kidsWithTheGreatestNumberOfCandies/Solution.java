// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

package kidsWithTheGreatestNumberOfCandies;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public List<Boolean> kidsWithCandies(int[] candies, int extra) {
		int max = candies[0];
		for (int candy : candies)
			max = Math.max(max, candy);

		List<Boolean> res = new ArrayList<>();
		for (int candy : candies)
			res.add(candy + extra >= max);

		return res;
    }
}
