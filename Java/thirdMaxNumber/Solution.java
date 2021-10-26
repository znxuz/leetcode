// https://leetcode.com/problems/third-maximum-number/

package thirdMaxNumber;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int thirdMax(int[] nums) {
		Set<Integer> max3 = new HashSet<>();

		for (int i : nums) {
			max3.add(i);
			if (max3.size() > 3)
				max3.remove(Collections.min(max3));
		}

		if (max3.size() < 3)
			return Collections.max(max3);
		return Collections.min(max3);
	}

	// time complexity: O(n * log(n))
	// space complexity: O(1)
    public int thirdMaxSort(int[] nums) {
		Arrays.sort(nums);
		for (int i = 0; i < nums.length / 2; i++) {
			int tmp = nums[i];
			nums[i] = nums[nums.length - 1 - i];
			nums[nums.length - 1 - i] = tmp;
		}

		int maxCounter = 1;
		int max = nums[0];
		int prev = max;
		for (int i = 1; i < nums.length; i++) {
			if (prev != nums[i]) {
				maxCounter++;
				prev = nums[i];
			}
			if (maxCounter == 3) {
				max = prev;
				break;
			}
		}

		return max;
    }
}
