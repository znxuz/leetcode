// https://leetcode.com/problems/create-target-array-in-the-given-order/

package createTargetArrayInTheGivenOrder;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public int[] createTargetArray(int[] nums, int[] index) {
		// TODO n logn solution
		return null;
	}

	// time complexity: O(n^2)
	// space complexity: O(n)
    public int[] createTargetArrayBruteForce(int[] nums, int[] index) {
		List<Integer> list = new ArrayList<>();
		for (int i = 0; i < index.length; ++i) {
			list.add(index[i], nums[i]);
		}

		return list.stream().mapToInt(Integer::intValue).toArray();
    }

}
