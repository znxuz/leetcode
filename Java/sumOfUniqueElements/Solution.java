// https://leetcode.com/problems/sum-of-unique-elements/

package sumOfUniqueElements;

class Solution {

    public int sumOfUnique(int[] nums) {
		int[] cnts = new int[101];
		for (int n : nums)
			cnts[n]++;

		int sum = 0;
		for (int i = 0; i < cnts.length; ++i) {
			if (cnts[i] == 1)
				sum += i;
		}

		return sum;
    }
}
