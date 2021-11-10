// https://leetcode.com/problems/binary-tree-tilt/

package BinaryTreeTilt;

import utils.TreeNode;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int findTilt(TreeNode root) {
		var treeHelper = getHelper(root);
		return treeHelper.diffSum;
	}

	private TreeHelper getHelper(TreeNode root) {
		if (root == null)
			return new TreeHelper(null);

		var helper = new TreeHelper(root);
		var left = getHelper(root.left);
		var right = getHelper(root.right);

		helper.sum = helper.node.val + left.sum + right.sum;
		helper.diffSum = left.diffSum + right.diffSum
			+ Math.abs(left.sum - right.sum);

		return helper;
	}

	private class TreeHelper {

		private final TreeNode node;
		private int sum = 0;
		private int diffSum = 0;

		private TreeHelper(TreeNode node) {
			this.node = node;
		}

	}

	// time complexity: O(n^2)
	// space complexity: O(n^2)
    public int findTiltBrute(TreeNode root) {
		if (root == null)
			return 0;
		int leftSum = sum(root.left);
		int rightSum = sum(root.right);
		return findTiltBrute(root.left) + findTiltBrute(root.right)
			+ Math.abs(leftSum - rightSum);
    }

	private int sum(TreeNode root) {
		if (root == null)
			return 0;
		return sum(root.left) + sum(root.right) + root.val;
	}

}
