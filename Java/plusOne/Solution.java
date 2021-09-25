// https://leetcode.com/problems/plus-one/

package plusOne;

import java.util.Arrays;

class Solution {

    public int[] plusOne(int[] digits) {
		// TODO
		return null;
	}

	// digits.length <= 100 >> invalid solution
    public int[] plusOneStream(int[] digits) {
		int val = Arrays.stream(digits).reduce(0, (result, elem) -> result * 10 + elem);
		return String.valueOf(++val).chars().map(Character::getNumericValue).toArray();
    }
}
