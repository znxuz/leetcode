// https://leetcode.com/problems/cousins-in-binary-tree/

package cousinsInBinaryTree;

import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

import utils.TreeNode;

class Solution {

    public boolean isCousins(TreeNode root, int x, int y) {
		return isCousinsIter(root, x, y);
	}

	// use a queue and not a stack!
	// BFS iter
	// time complexity: O(n)
	// space complexity: O(n)
    public boolean isCousinsIter(TreeNode root, int x, int y) {
		if (root == null)
			return false;

		Set<Integer> targets = new HashSet<>();
		targets.add(x);
		targets.add(y);
		Deque<TreeNode> q = new LinkedList<>();
		q.offerLast(root);
		while (!q.isEmpty() && targets.size() == 2) {
			int sz = q.size();
			while (sz-- > 0) {
				var node = q.pollFirst();
				if (node == null)
					continue;
				if (node.left != null && targets.contains(node.left.val)) {
					targets.remove(node.left.val);
				} else if (node.right != null && targets.contains(node.right.val)) {
					targets.remove(node.right.val);
				} else {
					q.offerLast(node.left);
					q.offerLast(node.right);
				}
			}
			if (targets.size() == 0)
				return true;
		}

		return false;
    }

	// TODO Rec

}
