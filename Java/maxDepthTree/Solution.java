// https://leetcode.com/problems/maximum-depth-of-binary-tree/

package maxDepthTree;

import utils.TreeNode;

class Solution {

	public int maxDepthIter(TreeNode root) {
		// TODO itertive DFS
		return 0;
	}

	// time complextity: O(n)
	// space complextity: O(n)
    public int maxDepth(TreeNode root) {
		if (root == null)
			return 0;
		return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
