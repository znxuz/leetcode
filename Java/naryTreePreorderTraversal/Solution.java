// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

package naryTreePreorderTraversal;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

import utils.NaryTree.Node;

class Solution {

    public List<Integer> preorder(Node root) {
		List<Integer> list = new ArrayList<>();
		preorderIter(root, list);
		return list;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public void preorderIter(Node root, List<Integer> list) {
		if (root == null)
			return;

		Deque<Node> stack = new ArrayDeque<>();
		stack.offerLast(root);
		while (!stack.isEmpty()) {
			var node = stack.pollLast();
			list.add(node.val);
			for (int i = node.children.size() - 1; i >= 0; i--) {
				stack.offerLast(node.children.get(i));
			}
		}
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public void preorderRec(Node root, List<Integer> list) {
		if (root == null)
			return;
		list.add(root.val);
		for (var node : root.children)
			preorderRec(node, list);
    }
}
