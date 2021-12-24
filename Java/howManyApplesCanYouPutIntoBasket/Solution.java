// https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/

package howManyApplesCanYouPutIntoBasket;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {

	// counting sort / bucket sort
	// time complexity: O(n)
	// space complexity: O(1): fixed size array
    public int maxNumberOfApples(int[] weight) {
		int[] weights = new int[1001];
		int max = -1;
		for (int w : weight) {
			weights[w]++;
			max = Math.max(max, w);
		}

		int total = 0;
		int count = 0;
		for (int i = 0; i < weights.length && i <= max; ++i) {
			while (weights[i]-- > 0) {
				total += i;
				count++;
			}
			if (total > 5000) {
				while (total > 5000) {
					total -= i;
					count--;
				}
				break;
			}
		}

		return count;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int maxNumberOfApplesMaxHeap(int[] weight) {
		Queue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		int total = 0;
		for (int w : weight) {
			if (total + w > 5000) {
				if (pq.isEmpty() || pq.peek() <= w)
					continue;
				total -= pq.poll();
			}
			pq.offer(w);
			total += w;
		}

		return pq.size();
	}

	// time complexity: O(n logn)
	// space complexity: O(n) for sorting
    public int maxNumberOfApplesSort(int[] weight) {
		Arrays.sort(weight);
		int total = 0;
		int i = 0;
		for (; i < weight.length; ++i) {
			if (total + weight[i] > 5000)
				break;
			total += weight[i];
		}

		return i;
    }
}
