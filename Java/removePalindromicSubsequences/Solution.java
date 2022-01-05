// https://leetcode.com/problems/remove-palindromic-subsequences/

package removePalindromicSubsequences;

class Solution {

    public int removePalindromeSub(String s) {
		if (s == null || s.length() == 0)
			return 0;

		int l = 0;
		int r = s.length() - 1;
		while (l < r) {
			if (s.charAt(l) != s.charAt(r))
				return 2;
			l++;
			r--;
		}

		return 1;
    }
}
