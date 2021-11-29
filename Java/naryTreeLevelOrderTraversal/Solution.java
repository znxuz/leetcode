// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

package naryTreeLevelOrderTraversal;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

import utils.NaryTree.Node;

class Solution {

    public List<List<Integer>> levelOrder(Node root) {
		List<List<Integer>> ret = new ArrayList<>();
		levelOrderRec(root, ret, 0);
		return ret;
    }

	// time complexity; O(n)
	// spce complexity: O(n)
	private void levelOrderIter(Node root, List<List<Integer>> list) {
		if (root == null)
			return;

		Deque<Node> queue = new ArrayDeque<>();
		queue.offer(root);
		while (!queue.isEmpty()) {
			int size = queue.size();
			List<Integer> sub = new ArrayList<>();
			while (size-- > 0) {
				var node = queue.poll();
				sub.add(node.val);
				for (var child : node.children)
					queue.offer(child);
			}
			list.add(sub);
		}
	}

	private void levelOrderRec(Node root, List<List<Integer>> list, int level) {
		if (root == null)
			return;

		List<Integer> sub;
		if (list.size() - 1 < level) {
			sub = new ArrayList<>();
			list.add(sub);
		} else {
			sub = list.get(level);
		}
		sub.add(root.val);
		for (var child : root.children)
			levelOrderRec(child, list, level + 1);
	}
}
