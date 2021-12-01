// https://leetcode.com/problems/kth-largest-element-in-a-stream/

package kthLargestElementInStream;

import java.util.PriorityQueue;

class Solution {

	class KthLargest {

		private int k;
		PriorityQueue<Integer> pq = new PriorityQueue<>();

		public KthLargest(int k, int[] nums) {
			this.k = k;
			for (int n : nums)
				this.add(n);
		}

		public int add(int val) {
			pq.offer(val);
			if (pq.size() > k)
				pq.poll();
			return pq.peek();
		}

	}


	/**
	 * Your KthLargest object will be instantiated and called as such:
	 * KthLargest obj = new KthLargest(k, nums);
	 * int param_1 = obj.add(val);
	 */
}

