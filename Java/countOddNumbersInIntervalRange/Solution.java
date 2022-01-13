// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

package countOddNumbersInIntervalRange;

class Solution {

	// 2 - 6: 3, 5	   diff = 4; odd = 2;
	// 2 - 7: 3, 5, 7, diff = 5, odd = 3;
	// 3 - 7: 3, 5, 7, diff = 4; odd = 3;
	// 3 - 8: 3, 5, 7, diff = 5; odd = 3;
	// 3 - 9: 3, 5, 7, diff = 6; odd = 4;
	// 4 - 10 5, 7, 9, diff = 6; odd = 3;
	// time complexity: O(1)
	// space complexity: O(1)
    public int countOdds(int low, int high) {
		return (high - low) / 2 + ((low & 1) == 1 || (high & 1) == 1 ? 1 : 0);
		// return (high + 1) / 2 - low / 2;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int countOddsBruteForce(int low, int high) {
		int odd = 0;
		while (low <= high) {
			odd += (low & 1);
			low++;
		}

		return odd;
    }
}
