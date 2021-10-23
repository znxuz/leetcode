// https://leetcode.com/problems/sum-of-left-leaves/

package sumOfLeftLeaves;

import java.util.Stack;

import utils.TreeNode;

class Solution {

    public int sumOfLeftLeaves(TreeNode root) {
		return iterative(root);
	}

	private int iterative(TreeNode root) {
		if (root == null || (root.left == null && root.right == null))
			return 0;

		int sum = 0;
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		while (!stack.isEmpty()) {
			TreeNode current = stack.pop();
			if (current.left != null) {
				if (current.left.left == null && current.left.right == null)
					sum += current.left.val;
				else
					stack.push(current.left);
			}
			if (current.right != null) {
				if (current.right.left != null || current.right.right != null)
					stack.push(current.right);
			}
		}

		return sum;
	}

    private int recursive(TreeNode root) {
		int sum = 0;

		if (root == null || (root.left == null && root.right == null))
			return 0;
		if (root.left != null)
			sum = root.left.left == null && root.left.right == null ?
				root.left.val : recursive(root.left);
		if (root.right != null)
			sum += root.right.left == null && root.right.right == null ?
				0 : recursive(root.right);

		return sum;
    }
}
