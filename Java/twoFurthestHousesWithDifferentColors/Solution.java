// https://leetcode.com/problems/two-furthest-houses-with-different-colors/

package twoFurthestHousesWithDifferentColors;

class Solution {

	// time: O(n)
	// space: O(1)
    public int maxDistance(int[] colors) {
		int n = colors.length;
		int max = -1;
		for (int i = 1; i < n; ++i)
			if (colors[0] != colors[i])
				max = Math.max(max, i);
		for (int i = n - 2; i >= 0; --i)
			if (colors[n - 1] != colors[i])
				max = Math.max(max, n - 1 - i);

		return max;
    }
}
