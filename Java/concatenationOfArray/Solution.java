// https://leetcode.com/problems/concatenation-of-array/

package concatenationOfArray;

class Solution {

    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] res = new int[2 * n];
        for (int i = 0; i < n; ++i)
            res[i] = res[n + i] = nums[i];

        return res;
    }
}
