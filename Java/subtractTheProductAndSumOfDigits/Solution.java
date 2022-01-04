// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

package subtractTheProductAndSumOfDigits;

class Solution {

    public int subtractProductAndSum(int n) {
		int sum = 0;
		int product = 1;
		while (n > 0) {
			int last = n % 10;
			sum += last;
			product *= last;
			n /= 10;
		}

		return product - sum;
	}

    public int subtractProductAndSumRec(int n) {
		return productDigit(n) - sumDigit(n);
    }

	public int productDigit(int n) {
		if (n == 0)
			return 0;
		if (n < 10)
			return n;
		return n % 10 * productDigit(n / 10);
	}

	public int sumDigit(int n) {
		if (n == 0)
			return 0;
		return n % 10 + sumDigit(n / 10);
	}
}
