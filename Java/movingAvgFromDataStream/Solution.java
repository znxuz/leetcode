// https://leetcode.com/problems/moving-average-from-data-stream/

package movingAvgFromDataStream;

import java.util.ArrayDeque;
import java.util.Queue;

class MovingAverage {

	private final int limit;
	private int sum = 0;
	private final Queue<Integer> queue = new ArrayDeque<>();

    public MovingAverage(int size) {
		this.limit = size;
    }
    
	// time complexity: O(1)
	// space complexity: O(n)
    public double next(int val) {
		if (queue.size() == limit) {
			sum -= queue.poll();
		}
		queue.offer(val);
		sum += val;
		return (double)sum / queue.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
