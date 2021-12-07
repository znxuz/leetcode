// https://leetcode.com/problems/leaf-similar-trees/

package leafSimilarTree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import utils.TreeNode;

class Solution {

	// DFS
	// time complexity: O(n + m)
	// space complexity: O(h): h for height of both trees
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
		if (root1 == null && root2 == null)
			return true;
		Stack<TreeNode> s1 = new Stack<>();
		Stack<TreeNode> s2 = new Stack<>();
		s1.push(root1);
		s2.push(root2);
		while (!s1.isEmpty() && !s2.isEmpty()) {
			if (dfs(s1) != dfs(s2))
				return false;
		}

		return s1.isEmpty() && s2.isEmpty();
	}

	private int dfs(Stack<TreeNode> s) {
		while (true) {
            TreeNode node = s.pop();
            if (node.right != null) s.push(node.right);
            if (node.left != null) s.push(node.left);
            if (node.left == null && node.right == null) return node.val;
		}
	}

	// DFS
	// time complexity: O(n + m): n, m size of each tree
	// space complexity: O(n + m)
    public boolean leafSimilarList(TreeNode root1, TreeNode root2) {
		List<Integer> leaves1 = new ArrayList<>();
		List<Integer> leaves2 = new ArrayList<>();

		getLeavesRec(root1, leaves1);
		getLeavesRec(root2, leaves2);

		return leaves1.equals(leaves2);
    }

	private void getLeavesRec(TreeNode root, List<Integer> leaves) {
		if (root == null)
			return;
		if (root.left == null && root.right == null)
			leaves.add(root.val);
		getLeavesRec(root.left, leaves);
		getLeavesRec(root.right, leaves);
	}

}
