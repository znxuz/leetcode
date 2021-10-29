// https://leetcode.com/problems/assign-cookies/

package assignCookies;

import java.util.Arrays;

class Solution {

	// time complexity: O(n * log(n))
	// space complexity: O(1)
    public int findContentChildren(int[] g, int[] s) {
		Arrays.sort(g);
		Arrays.sort(s);
		int counter = 0;
		int i = g.length - 1;
		int j = s.length - 1;
		while (i >= 0 && j >= 0) {
			if (g[i] <= s[j]) {
				counter++;
				j--;
			}
			i--;
		}

		return counter;
    }
}
