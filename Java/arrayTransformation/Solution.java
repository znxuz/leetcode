// https://leetcode.com/problems/array-transformation/

package arrayTransformation;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {

    public List<Integer> transformArray(int[] arr) {
		boolean inc = true;
		int[] next;
		do {
			next = new int[arr.length];
			inc = false;
			for (int i = 0; i < arr.length; ++i) {
				next[i] = arr[i];
				if (i == 0 || i == arr.length - 1)
					continue;
				if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
					next[i]++;
				else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
					next[i]--;
				if (!inc)
					inc = next[i] != arr[i];
			}
			arr = next;
		} while (inc);

		return Arrays.stream(next).boxed().collect(Collectors.toList());
    }
}
