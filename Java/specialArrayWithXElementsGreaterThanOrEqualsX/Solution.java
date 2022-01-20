// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

package specialArrayWithXElementsGreaterThanOrEqualsX;

import java.util.Arrays;

class Solution {

	// time complexity: O(n logn)
	// space complexity: O(n)
    public int specialArray(int[] nums) {
		Arrays.sort(nums);
		int rest = nums.length;
		int max = nums[nums.length - 1];
		int idx = 0;
		for (int i = 0; i <= max; ++i) {
			if (i == rest)
				return i;
			while (idx < nums.length && i == nums[idx]) {
				idx++;
				rest--;
			}
		}

		return -1;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int specialArrayImproved(int[] nums) {
		int[] cnts = new int[nums.length + 1];
		for (int n : nums) {
			if (n >= nums.length)
				cnts[nums.length]++;
			else
				cnts[n]++;
		}
		int res = 0;
		for (int i = cnts.length - 1; i >= 0; --i) {
			res += cnts[i];
			if (res == i)
				return i;
		}

		return -1;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int specialArrayCountingSort(int[] nums) {
		int[] cnts = new int[1001];
		for (int n : nums) {
			cnts[n]++;
		}
		int total = nums.length;
		for (int i = 0; i < cnts.length; ++i) {
			if (i == total)
				return i;
			total -= cnts[i];
		}

		return -1;
    }
}
