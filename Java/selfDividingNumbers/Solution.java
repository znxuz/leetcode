// https://leetcode.com/problems/self-dividing-numbers/

package selfDividingNumbers;

import java.util.ArrayList;
import java.util.List;

class Solution {

	private boolean isDivisible(int num, int current) {
		if (current == 0)
			return true;
		int last = current % 10;
		return last != 0 && num % last == 0 && isDivisible(num, current / 10);
	}

    public List<Integer> selfDividingNumbers(int left, int right) {
		List<Integer> list = new ArrayList<>();
		while (left <= right) {
			if (isDivisible(left, left))
				list.add(left);
			left++;
		}

		return list;
    }
}
