// https://leetcode.com/problems/palindrome-number/

package palindromeNumber;

class Solution {

	// O(log_10(n))
	public boolean isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;

		int reverse = 0;
		while (x >  reverse) {
			reverse = reverse * 10 + x % 10;
			x /= 10;
		}

		return reverse == x || reverse / 10 == x;
	}

	// O(n)
    public boolean isPalindrome_alternative(int x) {
		String str = Integer.toString(x);
		if (new StringBuilder(str).reverse().toString().equals(str))
			return true;
		return false;
	}
}
