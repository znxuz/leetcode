// https://leetcode.com/problems/invert-binary-tree/

package invertBinaryTree;

import java.util.Stack;

import utils.TreeNode;

class Solution {

    public TreeNode invertTree(TreeNode root) {
		return invertTreeIter(root);
	}

	public TreeNode invertTreeIter(TreeNode root) {
		if (root == null)
			return null;

		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		while (!stack.isEmpty()) {
			var cur = stack.pop();
			var left = cur.left;
			var right = cur.right;
			cur.left = right;
			cur.right = left;
			if (left != null)
				stack.push(left);
			if (right != null)
				stack.push(right);
		}

		return root;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public TreeNode invertTreeRec(TreeNode root) {
		if (root == null)
			return null;
		var left = root.left;
		var right = root.right;
		root.left = invertTree(right);
		root.right = invertTree(left);
		return root;
    }
}
