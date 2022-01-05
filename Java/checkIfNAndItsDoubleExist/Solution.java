// https://leetcode.com/problems/check-if-n-and-its-double-exist/

package checkIfNAndItsDoubleExist;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// TODO two pointer
	// https://leetcode.com/problems/check-if-n-and-its-double-exist/discuss/1326179/Elegant-two-pointers-O(n)-for-sorted-otherwise-O(nlogn)

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean checkIfExistSet(int[] arr) {
		Set<Integer> set = new HashSet<>();
		for (int n : arr) {
			if (set.contains(n * 2) || (n % 2 == 0 && set.contains(n / 2)))
				return true;
			set.add(n);
		}

		return false;
    }
}
