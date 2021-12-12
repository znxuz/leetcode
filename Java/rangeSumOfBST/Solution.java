// https://leetcode.com/problems/range-sum-of-bst/

package rangeSumOfBST;

import java.util.Stack;

import utils.TreeNode;

class Solution {

    public int rangeSumBST(TreeNode root, int l, int h) {
		return rangeSumBSTIterBFS(root, l, h);
	}

	// iter DFS
	public int rangeSumBSTIterDFS(TreeNode root, int l, int h) {
		if (root == null)
			return -1;

		int res = 0;
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		while (!stack.isEmpty()) {
			var node = stack.pop();
			if (node == null)
				continue;
			if (node.val >= l && node.val <= h) {
				res += node.val;
				stack.push(node.left);
				stack.push(node.right);
			} else if (node.val < l) {
				stack.push(node.right);
			} else {
				stack.push(node.left);
			}
		}

		return res;
	}

	// rec DFS
    public int rangeSumBSTRecDFS(TreeNode root, int l, int h) {
		if (root == null)
			return 0;

		int res = root.val >= l && root.val <= h ? root.val : 0;
		if (res != 0)
			res += rangeSumBST(root.left, l, h) + rangeSumBST(root.right, l, h);
		else if (root.val < l)
			res += rangeSumBST(root.right, l, h);
		else
			res += rangeSumBST(root.left, l, h);

		return res;
    }

	// iter BFS
	public int rangeSumBSTIterBFS(TreeNode root, int l, int h) {
		if (root == null)
			return -1;

		int res = 0;
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		while (!stack.isEmpty()) {
			var size = stack.size();
			for (int i = 0; i < size; i++) {
				var node = stack.pop();
				if (node == null)
					continue;
				if (node.val >= l && node.val <= h)
					res += node.val;
				stack.push(node.left);
				stack.push(node.right);
			}
		}

		return res;
	}

}
