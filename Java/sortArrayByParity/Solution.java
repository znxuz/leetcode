// https://leetcode.com/problems/sort-array-by-parity/

package sortArrayByParity;

class Solution {

    public int[] sortArrayByParity(int[] nums) {
		int left = 0;
		int right = nums.length - 1;
		while (left < right) {
			if (nums[left] % 2 != 0) {
				while (right > left && nums[right] % 2 != 0)
					right--;
				int tmp = nums[left];
				nums[left] = nums[right];
				nums[right] = tmp;
			}
			left++;
		}

		return nums;
    }
}
