// https://leetcode.com/problems/move-zeroes/

package moveZeros;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
    public void moveZeroesTwoPointer(int[] nums) {
		int i = 0;
		for (int j = 0; i < nums.length; j++) {
			if (nums[j] != 0) {
				nums[i++] = nums[j];
			}
		}
		while (i < nums.length) {
			nums[i++] = 0;
		}
	}

	// time complexity: O(n^2)
    public void moveZeroesBubble(int[] nums) {
		int length = nums.length;
		for (int i = 0; i < length; i++) {
			for (int j = i + 1; j < length; j++) {
				if (nums[j - 1] == 0) {
					int tmp = nums[j];
					nums[j] = nums[j - 1];
					nums[j - 1] = tmp;
				}
			}
			if (nums[i] == 0)
				i--;
			length--;
		}
    }

	// time complexity: stream.filter + O(n)
	public void moveZerosStream(int[] nums) {
		int[] moved = Arrays.stream(nums).filter(x -> x != 0).toArray();
		for (int i = 0; i < nums.length; i++) {
			if (i < moved.length) {
				nums[i] = moved[i];
			} else {
				nums[i] = 0;
			}
		}
	}
}
