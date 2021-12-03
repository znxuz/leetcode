// https://leetcode.com/problems/design-hashmap/

package designHashMap;

import java.util.LinkedList;

class Solution {

}

// bruh cant believe i did it one try
class MyHashMap {

	private final Bucket[] buckets;
	private final int size = 769;

    public MyHashMap() {
		this.buckets = new Bucket[size];
		for (int i = 0; i < size; i++) {
			buckets[i] = new Bucket();
		}
    }

	private int hash(int key) {
		return key % size;
	}

    public void put(int key, int val) {
		int idx = hash(key);
		if (!buckets[idx].contains(key))
			buckets[idx].add(key, val);
		else
			buckets[idx].change(key, val);
    }

    public int get(int key) {
		if (buckets[hash(key)].contains(key))
			return buckets[hash(key)].get(key);
		return -1;
    }

    public void remove(int key) {
		if (buckets[hash(key)].contains(key))
			buckets[hash(key)].remove(key);
    }

	private class Bucket {

		private final LinkedList<int[]> list;

		private Bucket() {
			this.list = new LinkedList<>();
		}

		private boolean contains(int key) {
			return list.stream().anyMatch(pair -> pair[0] == key);
		}

		private void add(int key, int val) {
			list.add(new int[]{key, val});
		}

		private void change(int key, int val) {
			var pair = list.stream().filter(p -> p[0] == key).findFirst().orElseThrow();
			pair[1] = val;
		}

		private int get(int key) {
			return list.stream().filter(p -> p[0] == key).findFirst().orElseThrow()[1];
		}

		private void remove(int key) {
			list.removeIf(pair -> pair[0] == key);
		}

	}

}
