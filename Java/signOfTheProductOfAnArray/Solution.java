// https://leetcode.com/problems/sign-of-the-product-of-an-array/

package signOfTheProductOfAnArray;

class Solution {

    public int arraySign(int[] nums) {
		int cnt = 0;
		for (var n : nums) {
			if (n == 0)
				return 0;
			if (n < 0)
				cnt++;
		}

		return (cnt % 2 == 0) ? 1 : -1;
    }
}
