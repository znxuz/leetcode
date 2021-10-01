// https://leetcode.com/problems/plus-one/

package plusOne;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n) for creating a new array
    public int[] plusOne(int[] digits) {
		for (int i = digits.length - 1; i >= 0; i--) {
			if (digits[i] == 9) {
				digits[i] = 0;
			} else {
				digits[i]++;
				return digits;
			}
		}

		digits = new int[digits.length + 1];
		digits[0] = 1;
		return digits;
	}

    public int[] plusOne2N(int[] digits) {
		boolean expand = true;
		for (int i = 0; i < digits.length && expand; i++) {
			if (digits[i] != 9)
				expand = false;
		}

		int[] newDigits = new int[expand ? digits.length + 1 : digits.length];
		int digitLastIndex = expand ? newDigits.length - 2 : digits.length - 1;
		boolean carry = true;
		for (int i = newDigits.length - 1; i >= 0; i--) {
			if (digitLastIndex >= 0)
				newDigits[i] = digits[digitLastIndex--];
			if (carry) {
				newDigits[i]++;
				carry = newDigits[i] > 9 ? true : false;
				newDigits[i] %= 10;
			}
		}

		return newDigits;
	}

	// digits.length <= 100 >> invalid solution
    public int[] plusOneStream(int[] digits) {
		int val = Arrays.stream(digits).reduce(0, (result, elem) -> result * 10 + elem);
		return String.valueOf(++val).chars().map(Character::getNumericValue).toArray();
    }
}
