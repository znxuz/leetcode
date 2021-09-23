// https://leetcode.com/problems/reverse-integer/

package reverse_integer;

class Solution {

    public int reverse(int x) {
		int rev = 0;

		while (x != 0) {
			int last = x % 10;
			if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && last > 7))
				return 0;
			if (rev < Integer.MIN_VALUE / 10 || (rev == Integer.MIN_VALUE / 10 && last < -8))
				return 0;
			rev = rev * 10 + last;
			x /= 10;
		}

		return rev;
    }
}
