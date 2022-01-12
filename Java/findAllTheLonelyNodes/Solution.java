// https://leetcode.com/problems/find-all-the-lonely-nodes/

package findAllTheLonelyNodes;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

import utils.TreeNode;

class Solution {

    public List<Integer> getLonelyNodes(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		getLonelyNodesRec(root, false, res);
		return res;
	}

	// rec DFS
	public void getLonelyNodesRec(TreeNode root, boolean isLonely, List<Integer> res) {
		if (root == null)
			return;
		if (isLonely)
			res.add(root.val);
		getLonelyNodesRec(root.left, root.right == null, res);
		getLonelyNodesRec(root.right, root.left == null, res);
	}

	// BFS
	// time complexity: O(n)
	// space complexity: O(n)
    public List<Integer> getLonelyNodesBFS(TreeNode root, List<Integer> res) {
		if (root == null)
			return null;

		Deque<TreeNode> queue = new ArrayDeque<>();
		queue.offer(root);
		while (!queue.isEmpty()) {
			int count = queue.size();
			for (int i = 0; i < count; ++i) {
				var cur = queue.poll();
				if (cur.left == null && cur.right == null)
					continue;
				if (cur.left == null || cur.right == null) {
					var nonNull = cur.left == null ? cur.right : cur.left;
					res.add(nonNull.val);
					queue.offer(nonNull);
				} else {
					queue.offer(cur.left);
					queue.offer(cur.right);
				}
			}
		}

		return res;
    }

}
