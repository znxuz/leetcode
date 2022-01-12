// https://leetcode.com/problems/shuffle-the-array/

package shuffleTheArray;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int[] shuffleExtraArray(int[] nums, int n) {
		int[] res = new int[nums.length];
		int x = 0;
		int y = nums.length / 2;
		int i = 0;
		while (i < res.length) {
			res[i++] = nums[x++];
			if (i < res.length)
				res[i++] = nums[y++];
		}

		return res;
    }
}
