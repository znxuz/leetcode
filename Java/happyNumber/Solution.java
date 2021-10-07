// https://leetcode.com/problems/happy-number/

package happyNumber;

class Solution {

	public int crossSum(int n) {
		if (n < 10)
			return (int)Math.pow(n, 2);
		return crossSum(n / 10) + (int)Math.pow(n % 10, 2);
	}

    public boolean isHappy(int n) {
		int walker = crossSum(n);
		if (walker == 1)
			return true;

		int runner = crossSum(walker);
		while (walker != runner) {
			if (runner == 1 || walker == 1)
				return true;
			walker = crossSum(walker);
			runner = crossSum(crossSum(runner));
		}

		return false;
    }
}
