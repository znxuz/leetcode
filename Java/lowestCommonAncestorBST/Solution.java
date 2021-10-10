// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

package lowestCommonAncestorBST;

import utils.TreeNode;

class Solution {

	// because BST's properties, left nodes are always smaller than root and right vice versa
	// time complexity: O(n)
	// space complexity: O(n), O(1) if tail recursion optimization available
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		if (root == null || p == null || q == null)
			return null;

		int rootVal = root.val;
		int pVal = p.val;
		int qVal = q.val;
		if (rootVal < pVal && rootVal < qVal)
			return lowestCommonAncestor(root.right, p, q);
		if (rootVal > pVal && rootVal > qVal)
			return lowestCommonAncestor(root.left, p, q);
		return root;
	}

	// brute force recursive search
	// time complexity: O(n)
	// space complexity: O(n)
    public TreeNode lowestCommonAncestorBruteForce(TreeNode root, TreeNode p, TreeNode q) {
		if (root == null)
			return null;
		if (root == p || root == q)
			return root;

		var left = lowestCommonAncestor(root.left, p, q);
		var right = lowestCommonAncestor(root.right, p, q);
		if (left == null)
			return right;
		if (right == null)
			return left;
		if ((left == p || left == q) || (right == p || right == q))
			return root;
		if (left == p || left == q)
			return left;
		if (right == p || right == q)
			return right;

		return null;
    }
}
