// https://leetcode.com/problems/distribute-candies-to-people/

package distributeCandiesToPeople;

class Solution {

    public int[] distributeCandies(int candies, int people) {
		int[] heads = new int[people];
		int i = 0;
		while (candies > 0) {
			heads[i % people] += (i < candies ? ++i : candies);
			candies -= i;
		}

		return heads;
    }
}
