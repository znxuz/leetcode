// https://leetcode.com/problems/perfect-number/

package perfectNumber;

class Solution {

	// euclid-euler theorem
	//		2^(p-1) * (2^p - 1) where p is a prime number
	//		p = 2, 3, 5, 7, 13, 17, 19, 31 only primes that fit in 64-bit
	// time complexity: O(1)
	// space complexity: O(1)
    public boolean checkPerfectNumber(int num) {
		int[] primes = {2, 3, 5, 7, 13, 17, 19, 31};
		for (int p : primes) {
			if ((1 << (p - 1)) * ((1 << p) - 1) == num)
				return true;
		}

		return false;
	}

	// time limit exceeded
    public boolean checkPerfectNumberInvalid(int num) {
		int sum = 0;
		for (int i = 1; i <= num / 2; i++) {
			if (num % i == 0)
				sum += i;
		}

		return sum == num;
    }
}
