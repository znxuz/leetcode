// https://leetcode.com/problems/search-insert-position/

package searchInsertPosition;

class Solution {

	private int searchInsertBinarySearch(int[] nums, int left, int right, int target) {
		if (left == right)
			return target == nums[left] ? left : target < nums[left] ? left : left + 1;

		int mid = left + (right - left) / 2;
		if (nums[mid] > target)
			return searchInsertBinarySearch(nums, left, mid, target);
		else if (nums[mid] < target)
			return searchInsertBinarySearch(nums, mid + 1, right, target);
		return mid;
	}
	
    public int searchInsert(int[] nums, int target) {
		return searchInsertBinarySearch(nums, 0, nums.length - 1, target);
    }
}
