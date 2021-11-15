// https://leetcode.com/problems/maximum-product-of-three-numbers/

package maximumProductOfThreeNumbers;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int maximumProduct(int[] nums) {
		int min1, min2;
		int max1, max2, max3;
		min1 = min2 = Integer.MAX_VALUE;
		max1 = max2 = max3 = Integer.MIN_VALUE;

		for (int i : nums) {
			if (i < min1) {
				min2 = min1;
				min1 = i;
			} else if (i < min2) {
				min2 = i;
			}
			if (i > max1) {
				max3 = max2;
				max2 = max1;
				max1 = i;
			} else if (i > max2) {
				max3 = max2;
				max2 = i;
			} else if (i > max3) {
				max3 = i;
			}
		}

		return Math.max(min1 * min2 * max1,
				max1 * max2 * max3);
	}

	// time complexity: O(n * logn)
	// space complexity: O(logn) for sorting
    public int maximumProductSort(int[] nums) {
		Arrays.sort(nums);
		return Math.max(nums[0] * nums[1] * nums[nums.length -1],
				nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3]);
    }
}
