package utils;

public class TreeNode {
	public int val;
	public TreeNode left, right;

	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}

	TreeNode(int val) {
		this(val, null, null);
	}

	TreeNode() {
		this(0, null, null);
	}

}
