//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

package maxDepthOfNaryTree;

import java.util.ArrayDeque;
import java.util.Deque;

import utils.NaryTree.Node;

class Solution {

    public int maxDepth(Node root) {
		return maxDepthIter(root);
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int maxDepthIter(Node root) {
		if (root == null)
			return 0;

		int max = 0;
		Deque<Node> queue = new ArrayDeque<>();
		queue.push(root);
		while (!queue.isEmpty()) {
			int count = queue.size();
			while (count-- > 0) {
				var cur = queue.pollFirst();
				for (var child : cur.children)
					queue.offerLast(child);
			}
			max++;
		}

		return max;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxDepthRec(Node root) {
		if (root == null)
			return 0;

		int max = 0;
		for (int i = 0; i < root.children.size(); i++) {
			max = Math.max(max, maxDepthRec(root.children.get(i)));
		}

		return max + 1;
    }
}
