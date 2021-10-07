// https://leetcode.com/problems/reverse-bits/

package reverseBits;

public class Solution {

	// 8 4 2 1
	// 1 1 1 1
	// time complexity: O(1)
	// space complexity: O(1)
	public int reverseBitsClever(int n) {
		n = (n >>> 16) | (n << 16); // n = (n & 0x0000ffff >>> 16) | (n & 0xffff0000 << 16);
		n = ((n & 0xff00ff00) >>> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >>> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >>> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >>> 1) | ((n & 0x55555555) << 1);

		return n;
	}

	// time complexity: O(1) for a fixed 32 iterations
	// space complexity: O(1)
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
		int result = 0;
		for (int i = 0; i < 32; i++) {
			result += n & 1;
			n >>>= 1;
			if (i < 31)
				result <<= 1;
		}

		return result;
    }
}
