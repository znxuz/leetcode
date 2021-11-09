// https://leetcode.com/problems/diameter-of-binary-tree/

package diameterBST;

import utils.TreeNode;

class Solution {

	private int diameter;

    public int diameterOfBinaryTree(TreeNode root) {
		diameter = 0;
		longestPath(root);
		return diameter;
    }

	private int longestPath(TreeNode root) {
		if (root == null)
			return 0;
		int leftMax = longestPath(root.left);
		int rightMax = longestPath(root.right);
		diameter = Math.max(diameter, leftMax + rightMax);
		return Math.max(leftMax, rightMax) + 1;
	}

}
