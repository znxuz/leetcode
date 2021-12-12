// https://leetcode.com/problems/number-of-recent-calls/

package numberOfRecentCalls;

import java.util.LinkedList;
import java.util.Queue;

class Solution {

	class RecentCounter {

		Queue<Integer> q = new LinkedList<>();

		public RecentCounter() {
		}
		
		public int ping(int t) {
			q.offer(t);
			while (t - q.peek() > 3000)
				q.poll();

			return q.size();
		}
	}

}
