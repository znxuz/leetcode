// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

package twoSumIV;

import java.util.Stack;

import utils.TreeNode;

class Solution {

	private int getTreeSize(TreeNode root) {
		if (root == null)
			return 0;
		return 1 + getTreeSize(root.left) + getTreeSize(root.right);
	}

	void inorder(int[] inorder, TreeNode root) {
		if (root == null)
			return;

		Stack<TreeNode> stack = new Stack<>();
		int i = 0;
		while (root != null || !stack.isEmpty()) {
			if (root != null) {
				stack.push(root);
				root = root.left;
			} else {
				root = stack.pop();
				inorder[i++] = root.val;
				root = root.right;
			}
		}
	}

    public boolean findTarget(TreeNode root, int k) {
		int[] inorder = new int[getTreeSize(root)];
		inorder(inorder, root);
		int left = 0;
		int right = inorder.length - 1;
		while (left < right) {
			int sum = inorder[left] + inorder[right];
			if (sum == k)
				return true;
			if (sum > k)
				right--;
			else
				left++;
		}

		return false;
    }
}
