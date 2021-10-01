// https://leetcode.com/problems/climbing-stairs/

package climbingStairs;

class Solution {

	private final int[] steps = new int[45];

	// time complexity: O(n^2) without memoization, O(n) with momoization
	// space complexity: O(n) recursions
    public int climbStairs(int n) {
		if (n < 3) {
			return n;
		} else {
			steps[n - 1] = steps[n - 1] == 0 ? climbStairs(n - 1) : steps[n - 1];
			steps[n - 2] = steps[n - 2] == 0 ? climbStairs(n - 2) : steps[n - 2];
			return steps[n - 1] + steps[n - 2]; 
		}
    }
}
