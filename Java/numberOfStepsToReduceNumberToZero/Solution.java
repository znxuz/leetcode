// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

package numberOfStepsToReduceNumberToZero;

class Solution {

    public int numberOfSteps(int num) {
		int ctr = 0;
		do {
			ctr += (num & 1) + 1;
			num >>>= 1;
		} while (num > 0);

		return ctr - 1;
	}

    public int numberOfStepsLinear(int num) {
		int ctr = 0;
		while (num > 0) {
			if (num % 2 == 0)
				num /= 2;
			else
				num--;
			ctr++;
		}

		return ctr;
    }
}
