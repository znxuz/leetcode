// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

package substringsOfSizeThreeWithDistinctCharacters;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int countGoodSubstringsLinear(String s) {
		int cnt = 0;
		for (int i = 0; i < s.length() - 2; ++i) {
			if (s.charAt(i) != s.charAt(i + 1)
					&& s.charAt(i + 1) != s.charAt(i + 2)
					&& s.charAt(i) != s.charAt(i + 2))
				cnt++;
		}

		return cnt;
    }
}
