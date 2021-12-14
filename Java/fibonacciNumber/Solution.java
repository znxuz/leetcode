// https://leetcode.com/problems/fibonacci-number/

package fibonacciNumber;

class Solution {

    public int fib(int n) {
		return fibMemo(n, new int[n + 1]);
		// return fibDp(n);
    }

	public int fibMemo(int n, int[] memo) {
		if (n < 0)
			return -1;

		memo[n] = n < 2 ? n : memo[n - 1] + memo[n - 2];
		return n < 2 ? memo[n] : fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
	}

	public int fibDp(int n) {
		int[] seq = new int[n + 1];
		for (int i = 0; i < seq.length; ++i) {
			seq[i] = i < 2 ? i : seq[i - 1] + seq[i - 2];
		}

		return seq[n];
	}

	public int fibRec(int n) {
		if (n < 0)
			return -1;
		if (n < 2)
			return n;
		return fibRec(n - 1) + fibRec(n - 2);
	}

}
