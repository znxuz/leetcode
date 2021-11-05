// https://leetcode.com/problems/find-mode-in-binary-search-tree/

package findModeInBST;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

import utils.TreeNode;

class Solution {

    public int[] findMode(TreeNode root) {
		if (root == null)
			return null;
		Map<Integer, Integer> map = new HashMap<>();
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		while (!stack.isEmpty()) {
			var current = stack.pop();
			map.put(current.val, map.getOrDefault(current.val, 0) + 1);
			if (current.left != null)
				stack.push(current.left);
			if (current.right != null)
				stack.push(current.right);
		}

		int max = Collections.max(map.values());
		List<Integer> list = new ArrayList<>();
		for (int i : map.keySet()) {
			if (map.get(i) == max)
				list.add(i);
		}

		int[] ret = new int[list.size()];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = list.get(i);
		}

		return ret;
    }
}
