// https://leetcode.com/problems/maximum-depth-of-binary-tree/

package maxDepthTree;

import java.util.ArrayDeque;
import java.util.Deque;

import utils.TreeNode;

class Solution {

    public int maxDepth(TreeNode root) {
		return maxDepthIter(root);
	}

	// time complexity: O(n)
	// space complexity: O(n)
	public int maxDepthIter(TreeNode root) {
		if (root == null)
			return 0;

		Deque<TreeNode> queue = new ArrayDeque<>();
		queue.offerLast(root);
		int max = 0;
		while (!queue.isEmpty()) {
			int count = queue.size();
			for (int i = 0; i < count; i++) {
				var node = queue.pollFirst();
				if (node.left != null)
					queue.offerLast(node.left);
				if (node.right != null)
					queue.offerLast(node.right);
			}
			max++;
		}

		return max;
	}

	// time complextity: O(n)
	// space complextity: O(n)
    public int maxDepthRec(TreeNode root) {
		if (root == null)
			return 0;
		return 1 + Math.max(maxDepthRec(root.left), maxDepthRec(root.right));
    }
}
