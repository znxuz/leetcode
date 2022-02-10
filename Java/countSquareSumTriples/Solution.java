// https://leetcode.com/problems/count-square-sum-triples/

package countSquareSumTriples;

class Solution {

    // time complexity: O(n^2)
    // space complexity: O(n^2)
    public int countTriples(int n) {
        boolean[] results = new boolean[n * n + 1];
        for (int i = 1; i <= n; ++i)
            results[i * i] = true;

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; i * i + j * j <= n * n; ++j)
                cnt += results[i * i + j * j] ? 2 : 0;
        }
        return cnt;
    }

    // time complexity: O(n^3)
    // space complexity: O(n)
    public int countTriplesBruteForce(int n) {
        int[] cnts = new int[n + 1];
        for (int i = 0; i < cnts.length; ++i)
            cnts[i] = (i == 0 ? 0 : cnts[i - 1]) + calc(i);
        return cnts[n];
    }

    private int calc(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i * i + j * j == n * n)
                    cnt++;
            }
        }
        return cnt;
    }
}
