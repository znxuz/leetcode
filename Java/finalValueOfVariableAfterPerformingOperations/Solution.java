// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

package finalValueOfVariableAfterPerformingOperations;

import java.util.Arrays;

class Solution {

    public int finalValueAfterOperations(String[] operations) {
		return Arrays.stream(operations).mapToInt(o -> o.charAt(1) == '-' ? -1 : 1).sum();
	}

    public int finalValueAfterOperationsLoop(String[] operations) {
		int i = 0;
		for (var o : operations) {
			if (o.charAt(1) == '-')
				i--;
			else
				i++;
		}
		return i;
    }
}
