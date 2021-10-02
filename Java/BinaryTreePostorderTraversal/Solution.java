// https://leetcode.com/problems/binary-tree-postorder-traversal/

package BinaryTreePostorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import utils.TreeNode;

class Solution {

	private void postorderTraversalIter(TreeNode root, List<Integer> postorder) {
		if (root == null)
			return;

		Stack<TreeNode> stack = new Stack<>();
		var current = root;
		while (current != null || !stack.isEmpty()) {
			if (current != null) {
				if (current.right != null)
					stack.push(current.right);
				stack.push(current);
				current = current.left;
			} else {
				current = stack.pop();
				if (!stack.isEmpty() && stack.peek() == current.right) {
					stack.pop();
					stack.push(current);
					current = current.right;
				} else {
					postorder.add(current.val);
					current = null;
				}
			}
		}
	}

	private void postorderTraversalRec(TreeNode root, List<Integer> postorder) {
		if (root == null)
			return;
		if (root.left != null)
			postorderTraversalRec(root.left, postorder);
		if (root.right != null)
			postorderTraversalRec(root.right, postorder);
		postorder.add(root.val);
	}
	
    public List<Integer> postorderTraversal(TreeNode root) {
		List<Integer> postorder = new ArrayList<>();
		postorderTraversalIter(root, postorder);
		return postorder;
    }
}
