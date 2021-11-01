// https://leetcode.com/problems/hamming-distance/

package hammingDistance;

class Solution {

	// Brian Kernighan's bit counting algorithm
	// skip all zeros between ones
	private int BKalgorithm(int x) {
		int count = 0;
		while (x != 0) {
			count++;
			x = x & (x - 1);
		}

		return count;
	}

	private int hammingWeight(int x) {
		int count = 0;
		while (x > 0) {
			count += (x & 1);
			x >>>= 1;
		}

		return count;
	}

    public int hammingDistance(int x, int y) {
		return BKalgorithm(x ^ y);
    }
}
