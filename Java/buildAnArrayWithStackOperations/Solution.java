// https://leetcode.com/problems/build-an-array-with-stack-operations/

package buildAnArrayWithStackOperations;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<String> buildArray(int[] target, int n) {
		List<String> res = new ArrayList<>();

		int idx = 0;
		for (int i = 1; i <= n && idx < target.length; ++i) {
			res.add("Push");
			if (target[idx] != i)
				res.add("Pop");
			else
				idx++;

		}

		return res;
    }
}
