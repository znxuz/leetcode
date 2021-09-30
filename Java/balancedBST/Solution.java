// https://leetcode.com/problems/minimum-depth-of-binary-tree/

package balancedBST;

import utils.TreeNode;

class Solution {

	private int getHeight(TreeNode root) {
		if (root == null)
			return 0;
		if (root.left == null && root.right == null)
			return 1;
		return 1 + Math.max(getHeight(root.left), getHeight(root.right));
	}

	// time complexity: O(n)?
	// space complextiy: O(n)
    public boolean isBalancedRec(TreeNode root) {
		if (root == null)
			return true;
		return Math.abs(getHeight(root.left) - getHeight(root.right)) > 1
			&& isBalanced(root.left) && isBalanced(root.right);
    }

	// time complexity: O(n)?
	// space complexity: O(n)
	public boolean isBalanced(TreeNode root) {
		return isBalancedHelper(root).isBalanced();
	}

	public TreeInfo isBalancedHelper(TreeNode root) {
		if (root == null)
			return new TreeInfo(0, true);
		if (root.left == null && root.right == null)
			return new TreeInfo(1, true);

		var left = isBalancedHelper(root.left);
		if (!left.isBalanced())
			return new TreeInfo(left.getHeight(), false);

		var right = isBalancedHelper(root.right);
		if (!right.isBalanced())
			return new TreeInfo(right.getHeight(), false);

		return new TreeInfo(Math.max(left.getHeight(), right.getHeight()) + 1,
				Math.abs(left.getHeight() - right.getHeight()) <= 1);
	}

	private class TreeInfo {
		private int height;
		private boolean isBalanced;

		private TreeInfo(int height, boolean isBalanced) {
			this.height = height;
			this.isBalanced = isBalanced;
		}

        public int getHeight() {
            return height;
        }

        public void setHeight(int height) {
            this.height = height;
        }

        public boolean isBalanced() {
            return isBalanced;
        }

        public void setBalanced(boolean isBalanced) {
            this.isBalanced = isBalanced;
        }

	}
}
