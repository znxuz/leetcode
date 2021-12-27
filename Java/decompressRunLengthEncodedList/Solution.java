// https://leetcode.com/problems/decompress-run-length-encoded-list/

package decompressRunLengthEncodedList;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int[] decompressRLElist(int[] nums) {
		int size = 0;
		for (int i = 0; i < nums.length; i += 2)
			size += nums[i];
		int[] ret = new int[size];
		int idx = 0;
		for (int i = 1; i < nums.length; i += 2) {
			Arrays.fill(ret, idx, idx + nums[i - 1], nums[i]);
			idx += nums[i - 1];
		}

		return ret;
    }
}
