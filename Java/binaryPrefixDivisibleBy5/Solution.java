// https://leetcode.com/problems/binary-prefix-divisible-by-5/

package binaryPrefixDivisibleBy5;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<Boolean> prefixesDivBy5(int[] nums) {
		List<Boolean> ret = new ArrayList<>();
		int num = 0;
		for (int i : nums) {
			num = (num * 2 + i) % 5;
			ret.add(num == 0);
		}

		return ret;
    }
}
