// https://leetcode.com/problems/complement-of-base-10-integer/

package complementOfBase10Integer;

class Solution {

    public int bitwiseComplement(int n) {
		if (n == 0)
			return 1;

		int flip = n;
		int bit = 1;
		while (n > 0) {
			flip ^= bit;
			bit <<= 1;
			n >>>= 1;
		}

		return flip;
	}

    public int bitwiseComplementIterFromLeft(int n) {
		if (n == 0)
			return 1;

		int ct = 0;
		for (int i = n; i > 0; i >>>= 1)
			ct++;
		int ret = 0;
		boolean first0 = false;
		while (ct > 0) {
			int bit = (n >>> --ct) & 1;
			if (!first0 && bit == 1)
				continue;
			first0 = true;
			ret <<= 1;
			if (bit == 0) {
				ret += 1;
			}
		}

		return ret;
    }
}
