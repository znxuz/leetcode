// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

package naryTreePostorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import utils.NaryTree.Node;

class Solution {

    public List<Integer> postorder(Node root) {
		List<Integer> list = new ArrayList<>();
		postorderIter(root, list);
		return list;
    }

	// 1. add root.val and then push(left to right) its children to stack, then return reversed list
	// 2. preorder but check if prev added val was the last child
	// 		if true then add val, else push(right to left -> preorder) it and it's children to stack
	private void postorderIter(Node root, List<Integer> list) {
		if (root == null)
			return;

		Stack<Node> stack = new Stack<>();
		stack.push(root);
		Node prev = null;
		while (!stack.isEmpty()) {
			var cur = stack.pop();
			if (cur.children.size() == 0 || prev == cur.children.get(cur.children.size() - 1)) {
				list.add(cur.val);
				prev = cur;
			} else {
				stack.push(cur);
				for (int i = cur.children.size() - 1; i >= 0; i--)
					stack.push(cur.children.get(i));
			}
		}
	}

	private void postorderRec(Node root, List<Integer> list) {
		if (root == null)
			return;
		for (var child : root.children) {
			postorderRec(child, list);
		}
		list.add(root.val);
	}
}
