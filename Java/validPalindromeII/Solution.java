// https://leetcode.com/problems/valid-palindrome-ii/

package validPalindromeII;

// edge case:
// cuppucu - delete last
// ucuppuc - delete first
// ------------------------
// cuptpucu - delete last
// ucuptpuc - delete first

class Solution {

    public boolean validPalindrome(String s) {
		int chance = 1;
		return validPalindromeRec(s, 0, s.length() - 1, chance);
    }

	private boolean validPalindromeRec(String s, int left, int right, int chance) {
		if (left >= right)
			return true;
		if (s.charAt(left) == s.charAt(right))
			return validPalindromeRec(s, ++left, --right, chance);
		return chance > 0
			&& (validPalindromeRec(s, left + 1, right, chance - 1)
					|| validPalindromeRec(s, left, right - 1, chance - 1));
	}

}
