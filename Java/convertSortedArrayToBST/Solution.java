// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

package convertSortedArrayToBST;

import utils.TreeNode;

class Solution {

	// TODO iterative DFS/BFS

	private TreeNode sortedArrayToBSTRec(int[] nums, int left, int right) {
		int mid = left + (right - left) / 2;
		var node = new TreeNode(nums[mid]);

		if (mid > left)
			node.left = sortedArrayToBSTRec(nums, left, mid - 1);
		if (mid < right)
			node.right = sortedArrayToBSTRec(nums, mid + 1, right);

		return node;
	}

    public TreeNode sortedArrayToBST(int[] nums) {
		if (nums == null)
			return null;
		return sortedArrayToBSTRec(nums, 0, nums.length - 1);
    }
}
