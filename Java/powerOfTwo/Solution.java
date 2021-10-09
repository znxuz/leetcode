// https://leetcode.com/problems/power-of-two/

package powerOfTwo;

class Solution {

	public boolean isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		return (n & -n) == n;
	}

	// time complexity: O(1)
	// space complexity: O(1)
    public boolean isPowerOfTwoBad(int n) {
		if (n <= 0)
			return false;
		boolean found1 = false;
		for (int i = 0; i < 32; i++) {
			if ((n & 1) == 1) {
				if (found1)
					return false;
				else
					found1 = true;
			}
			n >>>= 1;
		}

		return found1;
    }
}
