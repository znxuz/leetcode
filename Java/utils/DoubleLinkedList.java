package utils;

public class DoubleLinkedList<T> {

	public Node<T> head;
	public Node<T> tail;
	private int size = 0;

	DoubleLinkedList(T t) {
		tail = head = new Node<T>(t);
		size++;
	}

	public void add(T t) {
		add(new Node<>(t));
	}

	public void add(Node<T> node) {
		tail.next = node;
		node.prev = tail;
		tail = tail.next;
		size++;
	}

	public Node<T> remove(Node<T> node) {
		if (node == head && node == tail) {
			tail = head = null;
		} else if (node == head) {
			head = head.next;
			node.next = head.prev = null;
		} else if (node == tail) {
			tail = tail.prev;
			node.next = tail.next = null;
		} else {
			node.prev.next = node.next;
			node.next.prev = node.prev;
			node.next = node.prev = null;
		}
		size--;

		return node;
	}

	public int size() {
		return size;
	}

	public static class Node<T> {

		public T t;
		public Node<T> next;
		public Node<T> prev;

		Node(T t) {
			this.t = t;
			next = prev = null;
		}

		@Override
		public String toString() {
			return String.valueOf(this.t);
		}

	}
}

