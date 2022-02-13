// https://leetcode.com/problems/find-the-middle-index-in-array/

package findTheMiddleIndexInArray;

import java.util.HashMap;
import java.util.Map;

class Solution {

    // time complexity: O(n)
    // space complexity: O(n)
    public int findMiddleIndex(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        int sum = 0;
        for (int i = 0; i < nums.length; ++i) {
            map.putIfAbsent(sum * 2 + nums[i], i);
            sum += nums[i];
        }
        return map.getOrDefault(sum, -1);
    }

    // time complexity: O(2 * n) = O(n)
    // space complexity: O(1)
    public int findMiddleIndexTwoPass(int[] nums) {
        int sum = 0;
        for (int n : nums)
            sum += n;
        int left = 0;
        for (int i = 0; i < nums.length; ++i) {
            sum -= nums[i];
            if (left == sum)
                return i;
            left += nums[i];
        }

        return -1;
    }
}
