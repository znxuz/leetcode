// https://leetcode.com/problems/number-of-1-bits/

package numberOf1Bits;

public class Solution {

    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
		int counter = 0;
		while (n != 0) {
			counter += (n & 1);
			n >>>= 1;
		}

		return counter;
    }
}
