// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

package maximumProductDifferenceBetweenTwoPairs;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public int maxProductDifference(int[] nums) {
        int max1, max2, min1, min2;
        max1 = max2 = Integer.MIN_VALUE;
        min1 = min2 = Integer.MAX_VALUE;
        for (int n : nums) {
           if (n > max1) {
               max2 = max1;
               max1 = n;
           } else if (n > max2) {
               max2 = n;
           }
           if (n < min1) {
               min2 = min1;
               min1 = n;
           } else if (n < min2) {
               min2 = n;
           }
        }

        return max1 * max2 - min1 * min2;
    }
}
