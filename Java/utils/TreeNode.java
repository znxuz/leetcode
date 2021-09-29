package utils;

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

}
