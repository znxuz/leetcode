// https://leetcode.com/problems/implement-stack-using-queues/

package implementingStackUsingQueues;

import java.util.ArrayDeque;
import java.util.Deque;

class MyStack {

	private final Deque<Integer> queue;

    public MyStack() {
		queue = new ArrayDeque<>();
    }
    
    public void push(int x) {
		int size = queue.size();
		queue.offerLast(x);
		while (size-- > 0) {
			queue.offerLast(queue.pollFirst());
		}
    }
    
    public int pop() {
		return queue.pollFirst();
    }
    
    public int top() {
		return queue.peekFirst();
    }
    
    public boolean empty() {
		return queue.isEmpty();
    }
}

class MyStackTwoQueue {

	private final Deque<Integer> queue1;
	private final Deque<Integer> queue2;

    public MyStackTwoQueue() {
		queue1 = new ArrayDeque<>();
		queue2 = new ArrayDeque<>();
    }

	private Deque<Integer> getEmptyQueue() {
		return queue1.isEmpty() ? queue1 : queue2;
	}

	private Deque<Integer> getOccupiedQueue() {
		return queue1.isEmpty() ? queue2 : queue1;
	}

    public void push(int x) {
		var empty = getEmptyQueue();
		var occupied = getOccupiedQueue();

		empty.offerLast(x);
		if (empty != occupied) {
			while (!occupied.isEmpty())
				empty.offerLast(occupied.pollFirst());
		}
    }

    public int pop() {
		return getOccupiedQueue().pollFirst();
    }

    public int top() {
		return getOccupiedQueue().peekFirst();
    }

    public boolean empty() {
		return getOccupiedQueue().isEmpty();
    }

}
