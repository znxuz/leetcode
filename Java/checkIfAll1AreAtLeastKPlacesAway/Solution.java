// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

package checkIfAll1AreAtLeastKPlacesAway;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean kLengthApart(int[] nums, int k) {
		int anchor = -k - 1;
		for (int i = 0; i < nums.length; ++i) {
			if (nums[i] == 0)
				continue;
			if (i - anchor <= k)
				return false;
			anchor = i;
		}

		return true;
    }
}
