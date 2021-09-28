// https://leetcode.com/problems/same-tree/

package sameTree;

import java.util.Stack;

import utils.TreeNode;

class Solution {

	// time complexity: O(n + m)
	// space complexity: O(n) for a full stack
    public boolean isSameTreeIter(TreeNode p, TreeNode q) {
		var stack = new Stack<TreeNode>();
		stack.push(p);
		stack.push(q);
		while (!stack.isEmpty()) {
			q = stack.pop();
			p = stack.pop();

			if (p == null && q == null)
				continue;
			if (p == null || q == null)
				return false;
			if (q.val != p.val)
				return false;
			if (q.left == null && q.right == null
					&& p.left == null && p.right == null)
				continue;
			stack.push(p.right);
			stack.push(q.right);
			stack.push(p.left);
			stack.push(q.left);
		}

		return true;
	}

	// time complexity: O(n + m)
	// space complexity: O(n + N)
    public boolean isSameTreeRec(TreeNode p, TreeNode q) {
		if (p == null && q == null)
			return true;
		if (p == null || q == null)
			return false;
		return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    public boolean isSameTree(TreeNode p, TreeNode q) {
		return isSameTreeIter(p, q);
	}
}
