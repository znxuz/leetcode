// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

package checkIfArrayIsSortedAndRotated;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean check(int[] nums) {
		int n = nums.length;
		int k = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[(i + 1) % n] < nums[i])
				k++;
			if (k > 1)
				return false;
		}

		return true;
	}

	// time complexity: O(n^2)
	// space complexity: O(1)
    public boolean checkBruteForce(int[] nums) {
		int n = nums.length;
		for (int i = 0; i < n; ++i) {
			boolean ascend = true;
			int prev = nums[i];
			for (int j = (i + 1) % n; j != i && ascend; j = (j + 1) % n) {
				if (nums[j] < prev)
					ascend = false;
				prev = nums[j];
			}
			if (ascend)
				return true;
		}

		return false;
    }
}
