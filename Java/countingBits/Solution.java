// https://leetcode.com/problems/counting-bits/

package countingBits;

class Solution {

	// transition function: P(x) = P(x / 2) + (x mod 2)
	// time complexity: O(n)
	// spcae complexity: O(n)
    public int[] countBits(int n) {
		int[] ret = new int[n + 1];

		for (int i = 1; i <= n; i++) {
			ret[i] = ret[i >> 1] + (i & 1);
		}

		return ret;
	}

	// time complexity: O(n logn)
	// space complexity: O(n)
    public int[] countBitsIter(int n) {
		int[] ret = new int[n + 1];

		for (int i = 0; i <= n; i++) {
			ret[i] = hammingWeight(i);
		}

		return ret;
    }

	// from numberOf1Bits problem
    public int hammingWeight(int n) {
		int counter = 0;
		while (n != 0) {
			counter += (n & 1);
			n >>>= 1;
		}

		return counter;
    }

}
