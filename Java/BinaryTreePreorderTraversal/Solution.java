// https://leetcode.com/problems/binary-tree-preorder-traversal/

package BinaryTreePreorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import utils.TreeNode;

class Solution {

	private void preorderTraversalRec(TreeNode root, List<Integer> preorder) {
		if (root == null)
			return;

		preorder.add(root.val);
		if (root.left != null)
			preorderTraversalRec(root.left, preorder);
		if (root.right != null)
			preorderTraversalRec(root.right, preorder);
	}

	private void preorderTraversalIter(TreeNode root, List<Integer> preorder) {
		if (root == null)
			return;

		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		while (!stack.isEmpty()) {
			var current = stack.pop();
			preorder.add(current.val);
			if (current.right != null)
				stack.push(current.right);
			if (current.left != null)
				stack.push(current.left);
		}
	}

    public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> preorder = new ArrayList<>();
		preorderTraversalIter(root, preorder);
		return preorder;
    }
}
