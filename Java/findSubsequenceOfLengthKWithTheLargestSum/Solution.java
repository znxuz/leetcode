// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

package findSubsequenceOfLengthKWithTheLargestSum;

import java.util.PriorityQueue;

class Solution {

	// time: O(n * log(k))
	// space: O(n)
    public int[] maxSubsequence(int[] nums, int k) {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int n : nums) {
			if (pq.size() < k || pq.peek() < n) {
				if (pq.size() == k)
					pq.poll();
				pq.offer(n);
			}
		}

		int[] ret = new int[pq.size()];
		int i = 0;
		for (int n : nums) {
			if (pq.contains(n)) {
				ret[i++] = n;
				pq.remove(n);
			}
		}
		return ret;
    }
}
