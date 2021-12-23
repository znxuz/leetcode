// https://leetcode.com/problems/last-stone-weight/

package lastStoneWeight;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int lastStoneWeight(int[] stones) {
		Queue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());
		for (int n : stones)
			q.offer(n);
		while (q.size() > 1) {
			int diff = Math.abs(q.poll() - q.poll());
			if (diff != 0)
				q.offer(diff);
		}

		return q.isEmpty() ? 0 : q.poll();
    }
}
