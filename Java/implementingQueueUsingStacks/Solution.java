// https://leetcode.com/problems/implement-queue-using-stacks/

package implementingQueueUsingStacks;

import java.util.Stack;

class MyQueue {

	private final Stack<Integer> stack1;
	private final Stack<Integer> stack2;

    public MyQueue() {
		stack1 = new Stack<>();
		stack2 = new Stack<>();
    }

	private Stack<Integer> getEmptyStack() {
		return stack1.isEmpty() ? stack1 : stack2;
	}

	private Stack<Integer> getOccupiedStack() {
		return stack1.isEmpty() ? stack2 : stack1;
	}

	private void resetOccupiedStack() {
		var empty = getEmptyStack();
		var occupied = getOccupiedStack();
		while (!occupied.isEmpty()) {
			empty.push(occupied.pop());
		}
	}

	// time complexity: O(2n) -> O(n)
	// space complexity: O(1)
    public void push(int x) {
		resetOccupiedStack();
		var empty = getEmptyStack();
		var occupied = getOccupiedStack();
		empty.push(x);
		while (!occupied.isEmpty())
			empty.push(occupied.pop());
    }

    public int pop() {
		return getOccupiedStack().pop();
    }

    public int peek() {
		return getOccupiedStack().peek();
    }

    public boolean empty() {
		return getOccupiedStack().isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
