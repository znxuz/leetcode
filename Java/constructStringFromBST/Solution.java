// https://leetcode.com/problems/construct-string-from-binary-tree/

package constructStringFromBST;

import java.util.Stack;

import utils.TreeNode;

class Solution {

    public String tree2str(TreeNode root) {
		if (root == null)
			return "";
		if (root.left == null && root.right == null)
			return "" + root.val;
		String children = wrap(tree2str(root.left));
		if (root.right != null)
			children += wrap(tree2str(root.right));
		return root.val + children;
    }

	private String wrap(String str) {
		return "(" + str + ")";
	}

}
