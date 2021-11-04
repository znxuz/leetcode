// https://leetcode.com/problems/next-greater-element-i/

package nextGreaterElementI;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class Solution {

	public int[] nextGreaterElement(int[] nums1, int[] nums2) {
		Stack<Integer> stack = new Stack<>();
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums2.length; i++) {
			int current = nums2[i];
			while (!stack.isEmpty() && stack.peek() < current)
				map.put(stack.pop(), current);
			stack.push(current);
		}
		while (!stack.isEmpty())
			map.put(stack.pop(), -1);

		int[] ret = new int[nums1.length];
		for (int i = 0; i < nums1.length; i++) {
			ret[i] = map.get(nums1[i]);
		}

		return ret;
	}

	// n == nums1.length, m == nums2.length
	// time complexity: O(n * m);
	// space complexity: O(n)
    public int[] nextGreaterElementBruteForce(int[] nums1, int[] nums2) {
		int[] ret = new int[nums1.length];
		int ctr = 0;
		for (int i = 0; i < nums1.length; i++) {
			int idx = 0;
			for (int j = 0; j < nums2.length; j++) {
				if (nums1[i] == nums2[j]) {
					idx = j;
					break;
				}
			}
			int nextGreater = -1;
			for (int j = idx + 1; j < nums2.length; j++) {
				if (nums2[j] > nums2[idx]) {
					nextGreater = nums2[j];
					break;
				}
			}
			ret[ctr++] = nextGreater;
		}

		return ret;
    }
}
