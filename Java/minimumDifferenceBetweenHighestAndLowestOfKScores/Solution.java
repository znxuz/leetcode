// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

package minimumDifferenceBetweenHighestAndLowestOfKScores;

import java.util.Arrays;

class Solution {

    // time complexity: O(n * logn)
    // space complexity: O(n)
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int min = Integer.MAX_VALUE;
        for (int i = k - 1; i < nums.length; ++i)
            min = Math.min(min, nums[i] - nums[i - k + 1]);

        return min;
    }
}
