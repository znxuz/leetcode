// https://leetcode.com/problems/sort-array-by-parity-ii/

package sortArrayByParityII;

class Solution {

	// took me more than 1 hour
	// time complexity: O(n)
	// space complexity: O(1)
    public int[] sortArrayByParityII(int[] nums) {
		int left = 0;
		int right = nums.length - 1;

		while (left < right) {
			if ((left & 1) != (nums[left] & 1) && (right & 1) != (nums[right] & 1)) {
				swap(nums, left, right);
			} else {
				if ((left & 1) != (nums[left] & 1)) {
					int nextRight = right - 2;
					while ((left & 1) != (nums[nextRight] & 1) && nextRight - 2 > left)
						nextRight -= 2;
					swap(nums, left, nextRight);
				}
				if ((right & 1) != (nums[right] & 1)) {
					int nextLeft = left + 2;
					while ((right & 1) != (nums[nextLeft] & 1) && nextLeft + 2 < right)
						nextLeft += 2;
					swap(nums, nextLeft, right);
				}
			} 

			left++;
			right--;
		}
		
		return nums;
    }

	// improved solution
    public int[] sortArrayByParityIIImproved(int[] nums) {
		int j = 1;
		for (int i = 0; i < nums.length; i += 2) {
			if (nums[i] % 2 == 1) {
				while (nums[j] % 2 == 1)
					j += 2;
				swap(nums, i, j);
			}
		}

		return nums;
    }

	private void swap(int[] nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}
