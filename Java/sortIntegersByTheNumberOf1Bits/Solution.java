// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

package sortIntegersByTheNumberOf1Bits;

import java.util.Arrays;
import java.util.Comparator;

class Solution {

    public int[] sortByBitsComparator(int[] arr) {
		Comparator<Integer> comp = (i1, i2) -> {
			int res = Integer.compare(Integer.bitCount(i1), Integer.bitCount(i2));
			return (res == 0) ? Integer.compare(i1, i2) : res;
		};
		return Arrays.stream(arr).boxed().sorted(comp).mapToInt(Integer::intValue).toArray();
    }
}
