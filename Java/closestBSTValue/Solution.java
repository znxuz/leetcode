// https://leetcode.com/problems/closest-binary-search-tree-value/

package closestBSTValue;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import utils.TreeNode;

class Solution {

	// time complexity: O(log n)
	// space complexity: O(1)
	public int closestValueRec(TreeNode root, double target) {
		if (root == null)
			return -1;

		int result = root.val;
		if (root.val > target && root.left != null)
			result = closestValueRec(root.left, target);
		if (root.val < target && root.right != null)
			result = closestValueRec(root.right, target);

		return Math.abs(result - target) < Math.abs(root.val - target) ?
			result : root.val;
	}

	// time complexity: O(n), n := count of tree nodes
	// space complexity: O(n)
	public int closestValueInorder(TreeNode root, double target) {
		List<Integer> inorder = new ArrayList<>();
		inorderTraversal(root, inorder);

		return Collections.min(inorder,
				(i1, i2) -> Double.compare(Math.abs(i1 - target), Math.abs(i2 - target)));
	}

	private void inorderTraversal(TreeNode root, List<Integer> inorder) {
		if (root == null)
			return;
		inorderTraversal(root.left, inorder);
		inorder.add(root.val);
		inorderTraversal(root.right, inorder);
	}

}
