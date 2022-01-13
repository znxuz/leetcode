// https://leetcode.com/problems/number-of-good-pairs/

package numberOfGoodPairs;

class Solution {

	// 0 = 0
	// 1 = 0
	// 2 = 1 = 1 + 0;
	// 3 = 3 = 2 + 1
	// 4 = 6 = 3 + 3
	// 5 = 10 = 4 + 6
	// 6 = 15 = 5 + 10
	// time complexity: O(n)
	// space ocmplexity: O(1)
    public int numIdenticalPairs(int[] nums) {
		int res = 0;
		int[] cnts = new int[101];
		for (int n : nums) {
			res += cnts[n]++;
		}

		return res;
	}

    public int numIdenticalPairsBruteForce(int[] nums) {
		int cnt = 0;
		for (int i = 0; i < nums.length; ++i) {
			for (int j = i + 1; j < nums.length; ++j) {
				if (nums[i] == nums[j])
					cnt++;
			}
		}

		return cnt;
    }
}
