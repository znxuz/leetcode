// https://leetcode.com/problems/max-stack/

package maxStack;

import java.util.Stack;

class MaxStack {
    Stack<Integer> stack;
    Stack<Integer> maxStack;

    public MaxStack() {
        stack = new Stack<>();
        maxStack = new Stack<>();
    }

    public void push(int x) {
        int max = maxStack.isEmpty() ? x : maxStack.peek();
        maxStack.push(max > x ? max : x);
        stack.push(x);
    }

    public int pop() {
        maxStack.pop();
        return stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int peekMax() {
        return maxStack.peek();
    }

    public int popMax() {
        int max = peekMax();
        Stack<Integer> buffer = new Stack<>();
        while (top() != max)
			buffer.push(pop());
        pop();
        while (!buffer.isEmpty())
			push(buffer.pop());
        return max;
    }
}

class MaxStackDDL {

	static class DoubleLinkedList<T> {

		private Node<T> head;
		private Node<T> tail;
		private int size = 0;

		DoubleLinkedList(T t) {
			tail = head = new Node<T>(t);
			size++;
		}

		public void add(T t) {
			Node<T> node = new Node<>(t);
			tail.next = node;
			node.prev = tail;
			tail = tail.next;
			size++;
		}

		public T removeLast() {
			if (tail == head)
				return unlink(tail).getT();
			tail = tail.prev;
			return unlink(tail.next).getT();
		}

		public T removeFirst() {
			if (head == tail)
				return unlink(head).getT();
			head = head.next;
			return unlink(head.prev).getT();
		}

		public Node<T> unlink(Node<T> node) {
			// FIXME
			// unlink for head and tail
			if (head == node) {
				head = head.next;
				head.prev.next = null;
				head.prev = null;
			} else if (tail == node) {
				tail = tail.prev;
				tail.next.prev = null;
				tail.next = null;
			} else {
				node.prev = node.next;
				node.next = node.prev;
			}
			size--;
			return node;
		}

		public int size() {
			return size;
		}

		public Node<T> getHead() {
			return head;
		}

		public Node<T> getTail() {
			return tail;
		}

	}

	static class Node<T> {

		private final T t;
		private Node<T> next;
		private Node<T> prev;

		Node(T t) {
			this.t = t;
			next = prev = null;
		}

        public T getT() {
            return t;
        }

        public Node<T> getNext() {
            return next;
        }

        public void setNext(Node<T> next) {
            this.next = next;
        }

        public Node<T> getPrev() {
            return prev;
        }

        public void setPrev(Node<T> prev) {
            this.prev = prev;
        }

	}

}
