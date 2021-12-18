// https://leetcode.com/problems/high-five/

package highFive;

import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeMap;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int[][] highFive(int[][] items) {
		Map<Integer, PriorityQueue<Integer>> map = new TreeMap<>();
		for (var score : items) {
			PriorityQueue<Integer> q;
			if (!map.containsKey(score[0])) {
				q = new PriorityQueue<>();
				map.put(score[0], q);
			} else {
				q = map.get(score[0]);
			}
			if (q.size() == 5) {
				if (q.peek() >= score[1])
					continue;
				q.poll();
			}
			q.offer(score[1]);
		}

		int[][] scores = new int[map.size()][];
		int i = 0;
		for (var entry : map.entrySet()) {
			int avg = (int)entry.getValue().stream().mapToInt(Integer::intValue).average().getAsDouble();
			scores[i++] = new int[]{entry.getKey(), avg};
		}

		return scores;
    }
}
