// https://leetcode.com/problems/finding-3-digit-even-numbers/

package find3DigitEvenNumbers;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time: O(n)
	// space: O(n)
    public int[] findEvenNumbers(int[] digits) {
		List<Integer> res = new ArrayList<>();
		int[] freq = new int[10];
		for (int n : digits)
			freq[n]++;

		for (int i = 1; i < 10; ++i) {
			if (freq[i] == 0)
				continue;
			int first = i;
			freq[i]--;
			for (int j = 0; j < 10; ++j) {
				if (freq[j] == 0)
					continue;
				int second = first * 10 + j;
				freq[j]--;
				for (int k = 0; k < 9; k += 2) {
					if (freq[k] == 0)
						continue;
					res.add(second * 10 + k);
				}
				freq[j]++;
			}
			freq[i]++;
		}

		int[] ret = new int[res.size()];
		for (int i = 0; i < ret.length; ++i)
			ret[i] = res.get(i);
		return ret;
    }
}
