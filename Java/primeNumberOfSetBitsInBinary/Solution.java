// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

package primeNumberOfSetBitsInBinary;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int countPrimeSetBits(int left, int right) {
		int count = 0;
		while (left <= right) {
			count += (665772 >>> Integer.bitCount(left++) & 1);
		}

		return count;
	}

	// time complexity: O(n * m): n from left to right, m for checking prime from 2 to m
	// space complexity: O(1)
    public int countPrimeSetBitsBruteForce(int left, int right) {
		int count = 0;
		while (left <= right) {
			count += isPrime(Integer.bitCount(left++)) ? 1 : 0;
		}

		return count;
    }

	public boolean isPrime(int x) {
		if (x < 2)
			return false;
		if (x == 2)
			return true;
		for (int i = 2; i < x; i++) {
			if (x % i == 0)
				return false;
		}

		return true;
	}

}
