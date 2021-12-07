// https://leetcode.com/problems/binary-gap/

package binaryGap;

class Solution {

	// time complexity: O(log n) / O(1)
	// space complexity: O(1)
    public int binaryGap(int n) {
		int distance = 0;
		int anchor = 0;
		int i = 0;
		while (n > 0) {
			i++;
			if ((n & 1) == 1) {
				if (anchor == 0) {
					anchor = i;
				} else {
					distance = Math.max(distance, i - anchor);
					anchor = i;
				}
			}
			n >>>= 1;
		}

		return distance;
    }
}
