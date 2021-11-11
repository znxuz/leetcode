// https://leetcode.com/problems/subtree-of-another-tree/

package subTreeOfAnotherTree;

import utils.TreeNode;

class Solution {

	private boolean isSameTree(TreeNode root1, TreeNode root2) {
		if (root1 == null && root2 == null)
			return true;
		if (root1 == null || root2 == null)
			return false;
		return root1.val == root2.val
			&& isSameTree(root1.left, root2.left) && isSameTree(root1.right, root2.right);
	}

	// time complexity: O(n * m)
	// space complexity: O(1)
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
		if (root == null && subRoot == null)
			return true;
		if (root == null || subRoot == null)
			return false;
		if (isSameTree(root, subRoot))
			return true;
		return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }
}
