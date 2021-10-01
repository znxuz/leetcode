// https://leetcode.com/problems/path-sum/

package pathSum;

import utils.TreeNode;

class Solution {

	// TODO iterative DFS

	// time complexity: O(n)
	// space complexity: O(n)
	private boolean hasPathSumRec(TreeNode root, int targetSum, int currentSum) {
		if (root == null)
			return false;
		if (root.left == null && root.right == null)
			return root.val + currentSum == targetSum;
		return hasPathSumRec(root.left, targetSum, root.val + currentSum)
			|| hasPathSumRec(root.right, targetSum, root.val + currentSum);
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean hasPathSum(TreeNode root, int targetSum) {
		if (root == null)
			return false;
		targetSum -= root.val;
		if (root.left == null && root.right == null)
			return targetSum == 0;
		return hasPathSum(root.left, targetSum) || hasPathSum(root.right, targetSum);
    }
}
