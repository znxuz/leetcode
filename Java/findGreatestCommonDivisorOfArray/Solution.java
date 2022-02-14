// https://leetcode.com/problems/find-greatest-common-divisor-of-array/

package findGreatestCommonDivisorOfArray;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public int findGCD(int[] nums) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int n : nums) {
            min = Math.min(min, n);
            max = Math.max(max , n);
        }
        return gcd(min, max);
    }

    public int gcd(int a, int b) {
		return b > 0 ? gcd(b, a % b) : a;
    }
}
