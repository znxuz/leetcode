// https://leetcode.com/problems/guess-number-higher-or-lower/

package guessNumberHigherOrLower;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number (my guess too high)
 *			      1 if num is higher than the guess number (my guess too low)
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {

	// time complexity: O(log_3(n))
	// space complexity: O(1)
	public int guessNumberTernarySearch(int n) {
		int low = 1;
		int high = n;
		while (low <= high) {
			int mid1 = low + (high - low) / 3;
			int mid2 = high - (high - low) / 3;
			int res1 = guess(mid1);
			int res2 = guess(mid2);
			if (res1 == -1)
				high = mid1 - 1;
			else if (res2 == 1)
				low = mid2 + 1;
			else if (res1 != 0 && res2 != 0) {
				low = mid1 + 1;
				high = mid2 - 1;
			} else {
				return res1 == 0 ? mid1 : mid2;
			}
		}

		return high;
	}

	// time complexity: O(log_2(n))
	// spcae complexity: O(1)
	public int guessNumberBinarySearch(int n) {
		int left = 1;
		int right = n;
		int mid = -1;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (guess(mid) == -1)
				right = mid;
			else if (guess(mid) == 1)
				left = mid + 1;
			else
				return mid;
		}

		return right;
	}
}

class GuessGame {

	protected int guess(int num) {
		return -1;
	}
}
