// https://leetcode.com/problems/range-sum-query-immutable/

package rangeSumQueryImmutable;

class Solution {

}

// time complexity:
// 	O(n) for creating sums array
// 	O(1) for retriving data
// space complexity: O(n); n == nums.length
class NumArray {

	private final int[] sums;

    public NumArray(int[] nums) {
		sums = new int[nums.length + 1];
		for (int i = 0; i < nums.length; i++) {
			sums[i + 1] = sums[i] + nums[i];
		}
    }

    public int sumRange(int left, int right) {
		return sums[right + 1] - sums[left];
    }

}

class NumArrayLinear {

	private final int[] nums;

    public NumArrayLinear(int[] nums) {
		this.nums = nums;
    }

    public int sumRange(int left, int right) {
		int sum = 0;
		for (int i = left; i <= right; i++) {
			sum += nums[i];
		}
		return sum;
    }
}
