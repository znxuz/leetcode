// https://leetcode.com/problems/find-if-path-exists-in-graph/

package findIfPathExistsInGraph;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

class Solution {

	// TODO Union Find

	// BFS iter
	// time complexity: O(n * logn) + O(n)
	// space complexity: O(n^2)
    public boolean validPathBFSIter(int n, int[][] edges, int src, int dest) {
		if (src == dest)
			return true;

		Map<Integer, List<Integer>> graph = new HashMap<>();
		for (var e : edges) {
			var vertices0 = graph.getOrDefault(e[0], new ArrayList<Integer>());
			var vertices1 = graph.getOrDefault(e[1], new ArrayList<Integer>());
			vertices0.add(e[1]);
			vertices1.add(e[0]);
			graph.put(e[0], vertices0);
			graph.put(e[1], vertices1);
		}

		Deque<Integer> queue = new ArrayDeque<>();
		Set<Integer> visited = new HashSet<>();
		queue.offer(src);
		while (!queue.isEmpty()) {
			var cur = queue.poll();
			visited.add(cur);
			var vertices = graph.get(cur);
			if (vertices.contains(dest)) // premature check
				return true;
			for (var v : vertices) {
				if (!visited.contains(v))
					queue.offer(v);
			}
		}
		return false;
	}

	// DFS iter
	// n = count of all nodes
	// time complexity: O(n * logn) + O(n)
	// space comlexity: O(n^2) + O(n)
    public boolean validPathIterDFS(int n, int[][] edges, int src, int dest) {
		if (src == dest)
			return true;

		Map<Integer, List<Integer>> graph = new HashMap<>();
		for (var e : edges) {
			var vertices0 = graph.getOrDefault(e[0], new ArrayList<Integer>());
			var vertices1 = graph.getOrDefault(e[1], new ArrayList<Integer>());
			vertices0.add(e[1]);
			vertices1.add(e[0]);
			graph.put(e[0], vertices0);
			graph.put(e[1], vertices1);
		}

		Stack<Integer> stack = new Stack<>();
		Set<Integer> visited = new HashSet<>();
		stack.push(src);
		while (!stack.isEmpty()) {
			var cur = stack.pop();
			visited.add(cur);
			var vertices = graph.get(cur);
			if (vertices.contains(dest))
				return true;
			for (var v : vertices) {
				if (!visited.contains(v))
					stack.push(v);
			}
		}

		return false;
	}

	// DFS rec
	// time complexity: O(n * logn) + O(n^2)
	// space complexity: O(n^2) + O(n)
    public boolean validPathRecDFS(int n, int[][] edges, int src, int dest) {
		if (src == dest)
			return true;

		Map<Integer, List<Integer>> graph = new HashMap<>();
		for (var e : edges) {
			var vertices0 = graph.getOrDefault(e[0], new ArrayList<Integer>());
			var vertices1 = graph.getOrDefault(e[1], new ArrayList<Integer>());
			vertices0.add(e[1]);
			vertices1.add(e[0]);
			graph.put(e[0], vertices0);
			graph.put(e[1], vertices1);
		}

		return findPathRec(graph, src, dest, new HashSet<Integer>());
    }

	private boolean findPathRec(Map<Integer, List<Integer>> map, int src, int dest, Set<Integer> visited) {
		visited.add(src);

		var vertices = map.get(src);
		if (vertices.contains(dest))
			return true;
		for (var v : vertices) {
			if (!visited.contains(v) && findPathRec(map, v, dest, visited))
				return true;
		}

		return false;
	}
}
