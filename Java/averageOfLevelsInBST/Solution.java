// https://leetcode.com/problems/average-of-levels-in-binary-tree/

package averageOfLevelsInBST;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

import utils.TreeNode;

class Solution {

    public List<Double> averageOfLevels(TreeNode root) {
		if (root == null)
			return null;

		List<Double> avg = new ArrayList<>();
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		double sum;
		while (!queue.isEmpty()) {
			sum = 0;
			int count = queue.size();
			for (int i = 0; i < count; i++) {
				var node = queue.poll();
				sum += node.val;
				if (node.left != null)
					queue.offer(node.left);
				if (node.right != null)
					queue.offer(node.right);
			}
			avg.add(sum / count);
			sum = 0;
		}

		return avg;
	}

	//? DFS
	// time complexity: O(2n) = O(n) n for traversing the tree, n for calculating average
	// space complexity: O(n)
    public List<Double> averageOfLevelsDFS(TreeNode root) {
		Map<Integer, List<Integer>> map = new HashMap<>();
		treeToMap(map, root, 0);
		List<Double> averages = new ArrayList<>();
		for (var key : map.keySet()) {
			double avg = map.get(key).stream()
				.mapToInt(Integer::intValue)
				.average()
				.orElseThrow();
			averages.add(avg);
		}

		return averages;
    }

	private void treeToMap(Map<Integer, List<Integer>> map, TreeNode root, int index) {
		if (root == null)
			return;
		if (!map.containsKey(index)) {
			map.put(index, new ArrayList<Integer>());
		}
		map.get(index).add(root.val);
		treeToMap(map, root.left, index + 1);
		treeToMap(map, root.right, index + 1);
	}

}
