// https://leetcode.com/problems/power-of-three/

package powerOfThree;

class Solution {

	// works only with prime n num
    public boolean isPowerOfThree(int n) {
		return n > 0 && 1162261467 % n == 0;
	}

    public boolean isPowerOfThreeRec(int n) {
		if (n == 0)
			return false;
		if (n == 1)
			return true;

		return n % 3 == 0 && isPowerOfThree(n / 3);
    }
}
