// https://leetcode.com/problems/largest-perimeter-triangle/

package largestPerimeterTriangle;

import java.util.Arrays;

class Solution {

	// [1, 2, 2] 
    public int largestPerimeter(int[] nums) {
		Arrays.sort(nums);
		for (int i = nums.length - 1; i >= 2; --i) {
			int hypothenus = nums[i];
			int a = nums[i - 1], b = nums[i - 2];
			if (a + b > hypothenus)
				return hypothenus + a + b;
		}

		return 0;
    }
}
