// https://leetcode.com/problems/binary-number-with-alternating-bits/

package binaryNumberWithAlternatingBits;

class Solution {

    public boolean hasAlternatingBits(int n) {
		return (n & (n >>> 1)) == 0 && (n | (n >>> 2)) == n;
	}

    public boolean hasAlternatingBitsLoop(int n) {
		int prev = n % 2 == 0 ? 1 : 0;
		while (n > 0) {
			int bit = (n & 1);
			if (bit == prev)
				return false;
			prev = bit;
			n >>>= 1;
		}

		return true;
    }
}
