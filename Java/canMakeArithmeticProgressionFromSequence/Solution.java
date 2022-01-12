// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

package canMakeArithmeticProgressionFromSequence;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
	// 	explanation: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/720152/O(n)-time-O(1)-space
    public boolean canMakeArithmeticProgression(int[] arr) {
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int n : arr) {
			min = Math.min(min, n);
			max = Math.max(max, n);
		}
		if ((max - min) % (arr.length - 1) != 0)
			return false;

		int diff = (max - min) / (arr.length - 1);
		int i = 0;
		while (i < arr.length) {
			if (arr[i] == min + diff * i)
				i++;
			else if ((arr[i] - min) % diff != 0)
				return false;
			else {
				int pos = (arr[i] - min) / diff;
				if (pos < i || arr[pos] == arr[i])
					return false;
				int tmp = arr[i];
				arr[i] = arr[pos];
				arr[pos] = tmp;
			}
		}
		return true;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean canMakeArithmeticProgressionSet(int[] arr) {
		Set<Integer> set = new HashSet<>();
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int n : arr) {
			min = Math.min(min, n);
			max = Math.max(max, n);
			set.add(n);
		}
		int diff = max - min;
		if (diff % (arr.length - 1) != 0)
			return false;
		diff /= arr.length - 1;
		for (int i = 0; i < arr.length; ++i) {
			if (!set.contains(min))
				return false;
			min += diff;
		}

		return true;
	}

    public boolean canMakeArithmeticProgressionSort(int[] arr) {
		Arrays.sort(arr);
		int prog = 0;
		for (int i = 1; i < arr.length; ++i) {
			int diff = arr[i] - arr[i - 1];
			if (i == 1)
				prog = diff;
			else if (diff != prog)
				return false;
		}

		return true;
    }
}
