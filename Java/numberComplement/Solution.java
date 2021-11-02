// https://leetcode.com/problems/number-complement/

package numberComplement;

class Solution {

    public int findComplementSingleBitFlip(int num) {
		int steps = getMaxExpo(num);
		int bit = 1;
		while (steps-- > 0) {
			num ^= bit;
			bit <<= 1;
		}

		return num;
	}

    public int findComplement32Shift(int num) {
		int maxExpo = getMaxExpo(num);
		num = ~num;
		num <<= 32 - maxExpo;
		num >>>= 32 - maxExpo;
		return num;
    }

	private int getMaxExpo(int num) {
		if (num == 0)
			return 0;
		return 1 + getMaxExpo(num / 2);
	}

}
