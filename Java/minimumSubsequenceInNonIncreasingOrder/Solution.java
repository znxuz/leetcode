// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

package minimumSubsequenceInNonIncreasingOrder;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public List<Integer> minSubsequence(int[] nums) {
		int[] ctrs = new int[101];
		int sum = 0;
		for (int n : nums) {
			sum += n;
			ctrs[n]++;
		}

		List<Integer> res = new ArrayList<>();
		int part = 0;
		for (int i = ctrs.length - 1; i >= 0; --i) {
			while (ctrs[i] > 0 && part <= sum) {
				part += i;
				sum -= i;
				res.add(i);
				ctrs[i]--;
			}
			if (part > sum)
				break;
		}

		return res;
	}

	// time complexity: O(n logn)
	// space complexity: O(n) for sorting
    public List<Integer> minSubsequenceSort(int[] nums) {
		int sum = 0;
		for (int n : nums)
			sum += n;
		Arrays.sort(nums);
		int partSum = 0;
		List<Integer> res = new ArrayList<>();
		for (int i = nums.length - 1; i >= 0 && partSum <= sum; --i) {
			sum -= nums[i];
			partSum += nums[i];
			res.add(nums[i]);
		}

		return res;
    }

	// time complexity: O(n logn)
	// space complexity: O(n)
    public List<Integer> minSubsequencePriorityQueue(int[] nums) {
		PriorityQueue<Integer> pqueue = new PriorityQueue<>(Comparator.reverseOrder());
		int sum = 0;
		for (int n : nums) {
			sum += n;
			pqueue.offer(n);
		}

		List<Integer> res = new ArrayList<>();
		int partSum = 0;
		while (!pqueue.isEmpty() && partSum <= sum) {
			int n = pqueue.poll();
			sum -= n;
			partSum += n;
			res.add(n);
		}

		return res;
	}

}
