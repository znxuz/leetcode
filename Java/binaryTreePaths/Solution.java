// https://leetcode.com/problems/binary-tree-paths/

package binaryTreePaths;

import java.util.ArrayList;
import java.util.List;

import utils.TreeNode;

class Solution {

    public List<String> binaryTreePaths(TreeNode root) {
		List<String> paths = new ArrayList<>();
		binaryTreePathsRec(root, paths, "");
		return paths;
    }

	private void binaryTreePathsRec(TreeNode root, List<String> paths, String path) {
		if (root == null) {
			return;
		} else if (isLeaf(root)) {
			paths.add(path + root.val);
			return;
		}

		binaryTreePathsRec(root.left, paths, path + root.val + "->");
		binaryTreePathsRec(root.right, paths, path + root.val + "->");
	}

	private boolean isLeaf(TreeNode node) {
		return node.left == null && node.right == null;
	}

}
