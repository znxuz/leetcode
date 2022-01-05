// https://leetcode.com/problems/maximum-69-number/

package maximum69Number;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int maximum69Number(int num) {
		int ctr = 0;
		for (int i = num; i > 0; i /= 10)
			if (i % 10 == 6) ctr++;
		if (ctr == 0)
			return num;

		int max = 0;
		int base = 1;
		while (num > 0) {
			int last = num % 10;
			if (last == 6 && --ctr == 0)
				last = 9;
			max += base * last;
			base *= 10;
			num /= 10;
		}

		return max;
    }
}
