// https://leetcode.com/problems/add-digits/

package addDigits;

class Solution {

	private int getCrossSum(int num) {
		if (num < 10)
			return num;
		return num % 10 + getCrossSum(num / 10);
	}

    public int addDigitsMath(int num) {
        if (num == 0)
				return 0;
        if (num % 9 == 0)
			return 9;
        return num % 9;
	}

    public int addDigits(int num) {
		if (num > 9)
			return addDigits(getCrossSum(num));
		return num;
    }
}
