// https://leetcode.com/problems/univalued-binary-tree/

package univaluedBinaryTree;

import java.util.Stack;

import utils.TreeNode;

class Solution {

    public boolean isUnivalTree(TreeNode root) {
		return isUnivalTreeRec(root);
	}

    public boolean isUnivalTreeIter(TreeNode root) {
		if (root == null)
			return true;

		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		int prev = root.val;
		while (!stack.isEmpty()) {
			var node = stack.pop();
			if (node == null)
				continue;
			if (node.val != prev)
				return false;
			prev = node.val;
			stack.push(node.left);
			stack.push(node.right);
		}

		return true;
	}

    public boolean isUnivalTreeRec(TreeNode root) {
		if (root == null)
			return true;

		var left = root.left == null || root.val == root.left.val;
		var right = root.right == null || root.val == root.right.val;
		return left && right
			&& isUnivalTreeRec(root.left) && isUnivalTreeRec(root.right);
    }

}
