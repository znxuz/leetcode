// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

package minimumDistanceBetweenBSTNodes;

import java.util.ArrayList;
import java.util.List;

import utils.TreeNode;

class Solution {

	private int result;
	private int prev;

	// time complexity: O(n)
	// space complexity: O(1)
    public int minDiffInBST(TreeNode root) {
		result = prev = Integer.MAX_VALUE;
		inorderCompareInPlace(root);

		return result;
	}

	private void inorderCompareInPlace(TreeNode root) {
		if (root == null)
			return;
		inorderCompareInPlace(root.left);
		if (prev != result)
			result = Math.min(result, root.val - prev);
		prev = root.val;
		inorderCompareInPlace(root.right);
	}

	// inorder traverse get vals to list
	// time complexity: O(n)
	// space complexity: O(n)
    public int minDiffInBSTInorderList(TreeNode root) {
		if (root == null)
			return -1;

		List<Integer> inorder = new ArrayList<>();
		inorder(root, inorder);
		int ret = Integer.MAX_VALUE;
		for (int i = 0; i < inorder.size() - 1; i++) {
			int diff = inorder.get(i + 1) - inorder.get(i);
			ret = Math.min(ret, diff);
		}

		return ret;
    }

	private void inorder(TreeNode root, List<Integer> list) {
		if (root == null)
			return;

		inorder(root.left, list);
		list.add(root.val);
		inorder(root.right, list);
	}

}
