// https://leetcode.com/problems/build-array-from-permutation/

package buildArrayFromPermutation;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public int[] buildArray(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i)
            nums[i] += n * (nums[nums[i]] % n);

        for (int i = 0; i < n; ++i)
            nums[i] /= n;
        return nums;
    }
}
