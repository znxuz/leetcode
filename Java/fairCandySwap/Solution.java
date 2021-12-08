// https://leetcode.com/problems/fair-candy-swap/

package fairCandySwap;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n + m): n, m lengths of the arrays
	// space complexity: O(n)
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
		int aliceSum = sum(aliceSizes);
		int bobSum = sum(bobSizes);
		int delta = (aliceSum - bobSum) / 2;

		Set<Integer> set = new HashSet<>();
		for (int i : aliceSizes)
			set.add(i);
		for (int i : bobSizes) {
			if (set.contains(i + delta))
				return new int[]{i + delta, i};
		}

		return new int[]{-1, -1};
	}

	// time compleixty: O(2(n logn) + n + m) = O(nlogn)
	// space complexity: O(n) for sorting
    public int[] fairCandySwapSort(int[] aliceSizes, int[] bobSizes) {
		Arrays.sort(aliceSizes);
		Arrays.sort(bobSizes);
		int aliceSum = sum(aliceSizes);
		int bobSum = sum(bobSizes);

		int i = 0;
		int j = 0;
		while (i < aliceSizes.length || j < aliceSizes.length) {
			if (aliceSum - aliceSizes[i] + bobSizes[j] > bobSum - bobSizes[j] + aliceSizes[i])
				i++;
			else if (aliceSum - aliceSizes[i] + bobSizes[j] < bobSum - bobSizes[j] + aliceSizes[i])
				j++;
			else
				return new int[]{aliceSizes[i], bobSizes[j]};
		}

		return new int[]{-1, -1};
    }

	private int sum(int[] array) {
		int sum = 0;
		for (int i : array)
			sum += i;
		return sum;
	}

}
