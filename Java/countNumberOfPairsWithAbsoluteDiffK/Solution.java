// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

package countNumberOfPairsWithAbsoluteDiffK;

import java.util.HashMap;
import java.util.Map;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public int countKDifference(int[] nums, int k) {
        int[] cnts = new int[101];
        for (int n : nums)
            cnts[n]++;

        int cnt = 0;
        for (int i = k; i < cnts.length; ++i) {
            cnt += cnts[i] * cnts[i - k];
        }

        return cnt;
    }

    // time complexity: O(n)
    // space complexity: O(n)
    public int countKDifferenceMap(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) {
            map.put(n,map.getOrDefault(n, 0) + 1);
        }

        int cnt = 0;
        for (var n : map.keySet()) {
            cnt += map.get(n) * map.getOrDefault(n + k, 0);
        }
        return cnt;
    }

}
