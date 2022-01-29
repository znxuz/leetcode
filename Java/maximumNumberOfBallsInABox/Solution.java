// https://leetcode.com/problems/maximum-number-of-balls-in-a-box/

package maximumNumberOfBallsInABox;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int countBalls(int lo, int hi) {
		int[] cnts = new int[55]; // restraints for hi: 10^6
		for (int i = lo; i <= hi; ++i) {
			int num = i;
			int sum = 0;
			while (num > 0) {
				sum += num % 10;
				num /= 10;
			}
			cnts[sum]++;
		}
		int max = 0;
		for (int n : cnts)
			max = Math.max(max, n);
		return max;
    }
}
