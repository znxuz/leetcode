// https://leetcode.com/problems/increasing-order-search-tree/

package increasingOrderSearchTree;

import java.util.Stack;

import utils.TreeNode;

class Solution {

    public TreeNode increasingBST(TreeNode root) {
		return increasingBSTRec(root);
    }

	private TreeNode newRoot;
	private TreeNode p;
	private TreeNode increasingBSTRec(TreeNode root) {
		this.newRoot = null;
		inorder(root);

		return newRoot;
	}

	private void inorder(TreeNode root) {
		if (root == null)
			return;
		inorder(root.left);
		if (newRoot == null)
			newRoot = p = new TreeNode(root.val);
		else
			p = p.right = new TreeNode(root.val);
		inorder(root.right);
	}

	private TreeNode increasingBSTIter(TreeNode root) {
		if (root == null)
			return null;

		Stack<TreeNode> stack = new Stack<>();
		TreeNode newRoot = null, p = null;
		while (root != null || !stack.isEmpty()) {
			if (root != null) {
				stack.push(root);
				root = root.left;
			} else {
				root = stack.pop();
				if (p == null) {
					p = new TreeNode(root.val);
					newRoot = p;
				} else {
					p.right = new TreeNode(root.val);
					p = p.right;
				}
				root = root.right;
			}
		}

		return newRoot;
	}

}
