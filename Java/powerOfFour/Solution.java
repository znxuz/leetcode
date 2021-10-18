// https://leetcode.com/problems/power-of-four/

package powerOfFour;

class Solution {

	// n & (n - 1) == 0 for cases like 5(0b101), n & 1 == 0 won't work here
	// ((n & 0xaaaaaaaa) == 0) || n % 3 == 1
	// time complexity: O(1)
	// space complexity: O(1)
	public boolean isPowerOfFour(int n) {
		return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
	}

	// time complexity: O(logn)
	// space complexity: O(1)
    public boolean isPowerOfFourLoop(int n) {
		if (n <= 0)
			return false;
		while (n % 4 == 0)
			n /= 4;
		return n == 1;
	}

	// bit operation
	// time complexity: O(logn)
	// space complexity: O(1)
    public boolean isPowerOfFourBit(int n) {
		if (n <= 0)
			return false;

		int counter = 0;
		int index = 0;
		while (n > 0) {
			int lastBit = n & 1;
			if (lastBit == 1) {
				if (index % 2 != 0)
					return false;
				counter += (n & 1);
			}
			n >>>= 1;
			index++;
		}

		return counter == 1;
    }
}
