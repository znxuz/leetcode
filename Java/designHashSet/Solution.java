package designHashSet;

import java.util.LinkedList;

import utils.TreeNode;

class Solution {

	class MyHashSet {

		private final int size;
		private final Bucket[] bucket;

		public MyHashSet() {
			this.size = 769;
			this.bucket = new Bucket[size];
		}

		public void add(int key) {
			if (!this.contains(key))
				bucket[hash(key)].add(key);
		}

		public void remove(int key) {
			if (this.contains(key))
				bucket[hash(key)].remove(key);
		}

		private int hash(int key) {
			return key % size;
		}

		public boolean contains(int key) {
			return bucket[hash(key)].contains(key);
		}

		private class Bucket {

			private final TreeNode root;

			private Bucket(int val) {
				root = new TreeNode(val);
			}

			private boolean contains(int val) {
				var node = root;
				while (node != null) {
					if (val == node.val)
						return true;
					if (val < node.val)
						node = node.left;
					else
						node = node.right;
				}

				return false;
			}

			private void add(int val) {
				// TODO add & balance algorithm
			}

			private void remove(int val) {
				// TODO add & balance algorithm
			}

		}
	}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */

	// linked list bucket implementation
	// time complexity: O(N/K): N: all possible values; K: predefined size
	// space complexity: O(K * M): M: number of unique values
	class MyHashSetLinkedList {

		private final Bucket[] bucket;
		private final int size;

		public MyHashSetLinkedList() {
			this.size = 769;
			bucket = new Bucket[size];
			for (int i = 0; i < size; i++) {
				bucket[i] = new Bucket();
			}
		}

		protected int hash(int key) {
			return key % size;
		}

		public void add(int key) {
			int idx = hash(key);
			bucket[idx].add(key);
		}

		public void remove(int key) {
			if (contains(key)) {
				bucket[hash(key)].remove(key);
			}
		}

		public boolean contains(int key) {
			return bucket[hash(key)].contains(key);
		}

		private class Bucket {

			private final LinkedList<Integer> container;

			private Bucket() {
				this.container = new LinkedList<>();
			}

			private void add(Integer val) {
				if (!contains(val))
					this.container.add(val);
			}

			// careful of wrong method overload
			private boolean remove(Integer val) {
				return container.remove(val);
			}

			private boolean contains(Integer val) {
				return container.contains(val);
			}

		}

	}

}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
