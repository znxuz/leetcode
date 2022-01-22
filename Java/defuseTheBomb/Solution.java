// https://leetcode.com/problems/defuse-the-bomb/

package defuseTheBomb;

class Solution {

	// sliding window
	// time complexity: O(n)
	// space complexity: O(1)
    public int[] decrypt(int[] code, int k) {
		int n = code.length;
		int[] decrypt = new int[n];
		if (k == 0)
			return decrypt;

		int start = 1;
		int end = k;
		int sum = 0;
		if (k < 0) {
			start = n + k;
			end = n - 1;
		}
		for (int i = start; i <= end; ++i)
			sum += code[i];

		for (int i = 0; i < n; ++i) {
			decrypt[i] = sum;
			sum -= code[start++ % n];
			sum += code[++end % n];
		}

		return decrypt;
	}

    public int[] decryptBruteForce(int[] code, int k) {
		int n = code.length;
		int[] decrypt = new int[n];
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 1; j <= Math.abs(k); ++j) {
				int idx = (i + ((k < 0) ? -j : j)) % n;
				if (idx < 0)
					idx = n + idx;
				sum += code[idx];
			}
			decrypt[i] = sum;
		}

		return decrypt;
    }
}
