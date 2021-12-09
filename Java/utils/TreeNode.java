package utils;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class TreeNode {
	public int val;
	public TreeNode left, right;

	public TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}

	public TreeNode(int val) {
		this(val, null, null);
	}

	public TreeNode() {
		this(0, null, null);
	}

	public static TreeNode getTree(Integer[] arr) {
		TreeNode[] nodes = new TreeNode[arr.length];
		for (int i = arr.length - 1; i >= 0; i--) {
			if (arr[i] != null)
				nodes[i] = new TreeNode(arr[i]);
			if (i <= arr.length / 2 && arr[i] != null) {
				if (i * 2 + 1 < arr.length)
					nodes[i].left = nodes[i * 2 + 1];
				if (i * 2 + 2 < arr.length)
					nodes[i].right = nodes[i * 2 + 2];
			}
		}

		return nodes[0];
	}

	public static List<Integer> levelOrder(TreeNode root) {
		if (root == null)
			return null;

		List<Integer> levelOrder = new ArrayList<>();
		Deque<TreeNode> deque = new ArrayDeque<>();
		deque.offer(root);
		while (!deque.isEmpty()) {
			int size = deque.size();
			while (size-- > 0) {
				var node = deque.poll();
				levelOrder.add(node.val);
				if (node.left != null)
					deque.offer(node.left);
				if (node.right != null)
					deque.offer(node.right);
			}
		}

		return levelOrder;
	}

}
