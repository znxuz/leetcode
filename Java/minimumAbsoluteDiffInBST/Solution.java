// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

package minimumAbsoluteDiffInBST;

import utils.TreeNode;

class Solution {

	private TreeNode prev = null;
	private int minDiff = Integer.MAX_VALUE;

	// time complexity: O(n)
	// space complexity: O(1)
    public int getMinimumDifference(TreeNode root) {
		inorder(root);
		return minDiff;
	}

	private void inorder(TreeNode root) {
		if (root == null)
			return;
		inorder(root.left);
		if (prev != null)
			minDiff = Math.min(minDiff, root.val - prev.val);
		prev = root;
		inorder(root.right);
	}

	// time complexity: O(n)
	// space complexity: O(1)
	// helper functions getting most left/right unnecessary since this is BST
	// 	and min diff must occur between adjacent values
    public int getMinimumDifferenceMine(TreeNode root) {
		if (root == null)
			return -1;

		int leftMin, rightMin;
		leftMin = rightMin = Integer.MAX_VALUE;
		if (root.left != null) {
			var mostRight = getMostRightNode(root.left);
			leftMin = Math.min(root.val - root.left.val, root.val - mostRight.val);
			if (!isLeafNode(root.left))
				leftMin = Math.min(leftMin, getMinimumDifference(root.left));
		}
		if (root.right != null) {
			var mostLeft = getMostLeftNode(root.right);
			rightMin = Math.min(root.right.val - root.val, mostLeft.val - root.val);
			if (!isLeafNode(root.right))
				rightMin = Math.min(rightMin, getMinimumDifference(root.right));
		}

		return Math.min(leftMin, rightMin);
    }

	private boolean isLeafNode(TreeNode node) {
		return node != null && (node.left == null && node.right == null);
	}

	private TreeNode getMostRightNode(TreeNode node) {
		if (node == null)
			return null;
		if (node.right != null)
			return getMostRightNode(node.right);
		return node;
	}

	private TreeNode getMostLeftNode(TreeNode node) {
		if (node == null)
			return null;
		if (node.left != null)
			return getMostLeftNode(node.left);
		return node;
	}

}
