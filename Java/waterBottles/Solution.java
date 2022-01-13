// https://leetcode.com/problems/water-bottles/

package waterBottles;

class Solution {

	// simulation
	// time complexity: O(logn)
	// space complexity: O(1)
    public int numWaterBottles(int numBottles, int numExchange) {
		int emptyBottles = 0;
		int drank = 0;
		while (numBottles > 0 || emptyBottles >= numExchange) {
			drank += numBottles;
			emptyBottles += numBottles;
			numBottles = 0 + emptyBottles / numExchange;
			emptyBottles %= numExchange;
		}

		return drank;
    }
}
