// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

package secondMinimumNodeInBinaryTree;

import java.util.HashSet;
import java.util.Set;

import utils.TreeNode;

class Solution {

    public int findSecondMinimumValue(TreeNode root) {
		Set<Integer> set = new HashSet<>();
		traverse(root, set);
		int min1 = root.val;
		long ret = Long.MAX_VALUE;
		for (int i : set) {
			if (min1 < i && i < ret)
				ret = i;
		}

		return ret == Long.MAX_VALUE ? -1 : (int) ret;
	}

	private void traverse(TreeNode root, Set<Integer> set) {
		if (root == null)
			return;
		set.add(root.val);
		traverse(root.left, set);
		traverse(root.right, set);
	}

	int min1;
	long ret;
    public int findSecondMinimumValueAhHoc(TreeNode root) {
		if (root == null)
			return -1;

		min1 = root.val;
		ret = Long.MAX_VALUE;
		dfs(root);
		return ret == Long.MAX_VALUE ? -1 : (int)ret;
    }

	private void dfs(TreeNode root) {
		if (root == null)
			return;
		if (root.val > min1 && root.val < ret) {
			ret = root.val;
		} else if (root.val == min1) {
			dfs(root.left);
			dfs(root.right);
		}

	}

}
