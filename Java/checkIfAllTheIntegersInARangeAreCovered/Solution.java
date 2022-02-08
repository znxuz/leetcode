// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/

package checkIfAllTheIntegersInARangeAreCovered;

class Solution {

	// time complexity: O(n)
	// space complexity: O(51)
    public boolean isCoveredArray(int[][] ranges, int left, int right) {
		int[] cnts = new int[51];
		for (var r : ranges) {
			for (int i = r[0]; i <= r[1]; ++i)
				cnts[i]++;
		}
		for (int i = left; i <= right; ++i)
			if (cnts[i] == 0)
				return false;
		return true;
    }
}
