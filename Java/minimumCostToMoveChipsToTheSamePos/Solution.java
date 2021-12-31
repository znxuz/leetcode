// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

package minimumCostToMoveChipsToTheSamePos;

class Solution {

	// tricky problem to come up with the solution
	// think before code
	// time complexity: O(n)
	// space complexity: O(1)
    public int minCostToMoveChips(int[] pos) {
		int odd = 0;
		int even = 0;
		for (int n : pos) {
			if (n % 2 == 0)
				even++;
			else
				odd++;
		}
		return Math.min(odd, even);
    }
}
