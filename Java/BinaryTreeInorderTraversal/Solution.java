// https://leetcode.com/problems/binary-tree-inorder-traversal/

package BinaryTreeInorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import utils.TreeNode;

class Solution {

	private void traverseIter(TreeNode root, List<Integer> inorder) {
		if (root == null)
			return;

		var stack = new Stack<TreeNode>();
		while (root != null || !stack.isEmpty()) {
			if (root != null) {
				stack.push(root);
				root = root.left;
			} else {
				root = stack.pop();
				inorder.add(root.val);
				root = root.right;
			}
		}
	}

	@SuppressWarnings("unused")
	private void traverseRec(TreeNode root, List<Integer> inorder) {
		if (root == null)
			return;
		if (root.left != null)
			traverseRec(root.left, inorder);
		inorder.add(root.val);
		if (root.right != null)
			traverseRec(root.right, inorder);
	}

    public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> inorder = new ArrayList<>();

		// traverseRec(root, inorder);
		traverseIter(root, inorder);
		return inorder;
    }
}
