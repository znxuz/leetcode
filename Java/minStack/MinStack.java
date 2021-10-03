// https://leetcode.com/problems/min-stack/

package minStack;

import java.util.Stack;

import static java.lang.Math.min;

class MinStack {

	private final Stack<Integer> stack;
	private final Stack<int[]> minTracker;

    public MinStack() {
		stack = new Stack<>();
		minTracker = new Stack<>();
    }
    
    public void push(int val) {
		stack.push(val);
		if (minTracker.isEmpty()) {
			minTracker.push(new int[]{val, 1});
		} else {
			int[] currentMin = minTracker.peek();
			if (currentMin[0] == val)
				currentMin[1]++;
			else if (currentMin[0] > val)
				minTracker.push(new int[]{val, 1});
		}
    }
    
    public void pop() {
		int val = stack.pop();
		int[] currentMin = minTracker.peek();
		if (currentMin[0] == val) {
			if (currentMin[1] == 1)
				minTracker.pop();
			else
				currentMin[1]--;
		}
    }
    
    public int top() {
		return stack.peek();
    }
    
    public int getMin() {
		return minTracker.peek()[0];
    }
}

// time complexity: all operations: O(1)
// space complexity: O(n)
class MinStackSet {

	private final Stack<int[]> stack;

    public MinStackSet() {
		stack = new Stack<>();
    }
    
    public void push(int val) {
		if (stack.isEmpty()) {
			stack.push(new int[]{val, val});
		} else {
			int min = stack.peek()[1];
			stack.push(new int[]{val, min(min, val)});
		}
    }
    
    public void pop() {
		stack.pop();
    }
    
    public int top() {
		return stack.peek()[0];
    }
    
    public int getMin() {
		return stack.peek()[1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
