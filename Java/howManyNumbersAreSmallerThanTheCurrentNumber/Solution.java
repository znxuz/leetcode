// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

package howManyNumbersAreSmallerThanTheCurrentNumber;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] smallerNumbersThanCurrent(int[] nums) {
		int[] ctrs = new int[101];
		for (int n : nums)
			ctrs[n]++;

		int partial = 0;
		for (int i = 0; i < ctrs.length; ++i) {
			if (ctrs[i] != 0) {
				int tmp = ctrs[i];
				ctrs[i] = partial;
				partial += tmp;
			}
		}

		int[] res = new int[nums.length];
		for (int i = 0; i < res.length; ++i) {
			res[i] = ctrs[nums[i]];
		}

		return res;
    }
}
