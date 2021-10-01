// https://leetcode.com/problems/symmetric-tree/

package symmetricTree;

import java.util.Stack;

import utils.TreeNode;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
	private boolean isSymmetricIter(TreeNode root) {
		if (root == null) return true;
		var stack = new Stack<TreeNode>();
		stack.push(root.left);
		stack.push(root.right);
		TreeNode left, right;
		while (!stack.isEmpty()) {
			right = stack.pop();
			left = stack.pop();
			if (left == null && right == null) continue;
			if (left == null || right == null) return false;
			if (left.val != right.val) return false;
			stack.push(left.right);
			stack.push(right.left);
			stack.push(left.left);
			stack.push(right.right);
		}

		return true;
	}

	@SuppressWarnings("unused")
	// time complexity: O(n / 2) = O(n)
	// space complexity: O(n)
	private boolean isSymmetricRec(TreeNode left, TreeNode right) {
		if (left == null && right == null) return true;
		if (left == null || right == null) return false;
		return left.val == right.val && isSymmetricRec(left.left, right.right)
			&& isSymmetricRec(left.right, right.left);
	}

    public boolean isSymmetric(TreeNode root) {
		if (root == null) return true;
		return isSymmetricIter(root);
    }
}
